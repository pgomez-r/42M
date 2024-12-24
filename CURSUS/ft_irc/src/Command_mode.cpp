#include "ft_irc.hpp"

/**
 * @brief Function to parse, set and init the MODE command environment
 * 	1 - Check if user is authenticated, if not, finish here (only to protect nc connections)
 *	2 - Check if enough params (MIN "MODE #channelName" - show modes list string)
 *	3 - Check if channel exists
 *	4 - Check if user isOp
 *	(!) IF EVERYTHING ABOVE IS OK
 *	5 - Parse and store modes (i-k,t+ol) in string vector splitted by ','
 *	6 - Parse and store params ("param1 param2 param3") in string vector splitted by ' '
 *	7 - Iterate the modes vector -> check each char in each string to update sign, execute
 *			mode command or skip if none
 */
void Command::cmdMode()
{
	if (!this->_user.getAuthenticated())
		return (kickNonAuthenticatedUser(this->_user.getFd()));
	
	std::vector<std::string> args = splitMessage(this->_msg, ' ');
	if (args.size() < 2)
		return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));
		
	std::string channelName = args[1];
	channelName.erase(channelName.find_last_not_of(" \n\r\t") + 1);
	this->_currChannel = this->_server.getChannelByName(channelName);
	if (!this->_currChannel)
		return (this->sendResponse(ERR_NOSUCHCHANNEL, MOD_USER, 0));
	if (args.size() == 2)
		return (this->sendResponse(RPL_CHANNELMODEIS, MOD_USER, 0),
			this->sendResponse(RPL_CREATIONTIME, MOD_USER, 0));
	if (!this->_currChannel->isOp(this->_user))
		return (this->sendResponse(ERR_CHANOPRIVSNEEDED, MOD_USER, 0));
	
	this->_modes = splitMessage(args[2], ',');
	for (size_t i = 3; i < args.size(); i++)
	{	
		args[i].erase(args[i].find_last_not_of(" \n\r\t") + 1);
		this->_params.push_back(args[i]);
	}

	for (size_t i = 0; i < this->_modes.size(); i++)
	{
		char	sign = '+';
		
		this->_modes[i].erase(this->_modes[i].find_last_not_of(" \n\r\t") + 1);
		for (size_t j = 0; j < this->_modes[i].size(); j++)
		{
			if (this->_modes[i][j] == '+' || this->_modes[i][j] == '-')
				sign = this->_modes[i][j];
			else if (this->_modes[i][j] == 'i' || this->_modes[i][j] == 'k' || this->_modes[i][j] == 'l' || this->_modes[i][j] == 'o' || this->_modes[i][j] == 't')
				execModes(sign, this->_modes[i][j]);
			else
			{
				this->_unknowFlags = this->_modes[i][j];
				this->sendResponse(ERR_UMODEUNKNOWNFLAG, MOD_USER, 0);
				continue;
			}
		}
	}
}

/**
 * @brief Function to execute the mode command according to the character and sign
 * @param sign + / -
 * @param mode iktol - if not one of those, error
 */
void Command::execModes(const char sign, const char mode)
{
	User		*target_user = NULL;
	std::string	msg = "MODE " + this->_currChannel->getName() + " ";

	switch (mode)
	{
		case 'i':
			if (sign == '+' && !this->_currChannel->getInviteMode())
			{
				this->_currChannel->setInviteMode(true);
				this->_currChannel->updateMode('i', 0);
				msg.append("+i");
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			else if (sign == '-' && this->_currChannel->getInviteMode())
			{
				this->_currChannel->setInviteMode(false);
				this->_currChannel->updateMode('i', 1);
				msg.append("-i");
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			break;
		case 'k':
			if (this->_paramCount >= this->_params.size() || this->_params.size() == 0)
			{
				this->_errorMsg = " :'k'";
				return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));
			} 
			if ((sign == '+' && !this->_currChannel->getKeyMode())
				|| (sign == '+' && this->_currChannel->getKeyMode() && this->_currChannel->getPassword() != this->_params[this->_paramCount]))
			{
				this->_currChannel->setPassword(this->_params[this->_paramCount]);
				this->_currChannel->setKeyMode(true);
				this->_currChannel->updateMode('k', 0);
				msg.append("+k ");
				msg.append(this->_params[this->_paramCount]);
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			else if (sign == '-' && this->_currChannel->getKeyMode())
			{
				if (this->_currChannel->getPassword() != this->_params[this->_paramCount])
				{
					this->_paramCount++;
					return (this->sendResponse(ERR_KEYSET, MOD_USER, 0));
				}
				this->_currChannel->setKeyMode(false);
				this->_currChannel->setPassword("");
				this->_currChannel->updateMode('k', 1);
				msg.append("-k");
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			this->_paramCount++;
			break;
		case 'l':
			if (sign == '+')
			{
				if (this->_paramCount >= this->_params.size() || this->_params.size() == 0
					|| !isOnlyDigits(this->_params[this->_paramCount]) || atoi(this->_params[this->_paramCount].c_str()) <= 0)
				{
					this->_errorMsg = " :'l'";
					return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));
				}
				if (this->_currChannel->getUsersLimit() != atoi(this->_params[this->_paramCount].c_str()))
				{	
					this->_currChannel->setUsersLimit(atoi(this->_params[this->_paramCount].c_str()));
					this->_currChannel->updateMode('l', 0);
					msg.append("+l ");
					msg.append(this->_params[this->_paramCount]);
					this->_server.messageToClient(msg, this->_user, this->_user);
					this->_paramCount++;
				}
			}
			else if (sign == '-')
			{
				if (this->_currChannel->getUsersLimit() != -1)
				{
					this->_currChannel->setUsersLimit(-1);
					this->_currChannel->updateMode('l', 1);
					msg.append("-l");
					this->_server.messageToClient(msg, this->_user, this->_user);
				}
			}
			break;
		case 'o':
			if (this->_paramCount >= this->_params.size() || this->_params.size() == 0)
			{
				this->_errorMsg = " :'o'";
				return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));
			}
			target_user = this->_server.getUserByNick(this->_params[this->_paramCount]);
			if (!target_user || !this->_currChannel->isUserInChannel(*target_user))
			{
				this->_errorMsg = this->_params[this->_paramCount];
				this->_paramCount++;
				return (this->sendResponse(ERR_USERNOTINCHANNEL, MOD_USER, 0));
			}
			if (sign == '+' && !this->_currChannel->isOp(*target_user))
			{
				this->_currChannel->addOpChannel(*target_user);
				msg.append("+o ");
				msg.append(this->_params[this->_paramCount]);
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			else if (sign == '-' && this->_currChannel->isOp(*target_user))
			{
				this->_currChannel->deleteOpChannel(*target_user);
				msg.append("-o ");
				msg.append(this->_params[this->_paramCount]);
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			this->_paramCount++;
			break;
		case 't':
			if (sign == '+' && !this->_currChannel->getTopicMode())
			{
				this->_currChannel->setTopicMode(true);
				this->_currChannel->updateMode('t', 0);
				msg.append("+t");
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			else if (sign == '-' && this->_currChannel->getTopicMode())
			{
				this->_currChannel->setTopicMode(false);
				this->_currChannel->updateMode('t', 1);
				msg.append("-t");
				this->_server.messageToClient(msg, this->_user, this->_user);
			}
			break;
		default:
			break;
	}
}
