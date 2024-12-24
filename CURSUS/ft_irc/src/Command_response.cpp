#include "ft_irc.hpp"

/**
 * @brief Function to send a response from the server to one or several clients with the
 * 	proper IRC protocol format and code
 * (!) First it generates the prefix of all responses, then completes it according to the
 * 	code of the response
 * @var response is the "prefix" message of the response
 * @var detail is the specific message for each response code
 * @param code the response code to be checked later in the response enum
 * @param mode value to send the response in different ways
 * @param fd if != 0, set the specific socketFd to send the response
 * 		MOD_CAST(1) - send response to all but the user that executed the command
 * 		MOD_ALL(2) - send response to all users including the one executing the command
 * 		MOD_USER(0) or ANY - send response ONLY to the user executing the command
 */
void	Command::sendResponse(int code, int mode, int fd)
{
	std::string	response = ":" + this->_server.getName() + " " + toString(code);
	std::string	detail = this->composeResponse(code);
	response.append(detail);
	std::cout << "[SERVER]->to->client raw message -> " << response << std::endl;
	if (fd != 0)
		send(fd, response.c_str(), response.size(), 0);
	else if (mode == MOD_CAST)
	{
		std::map<User*, bool>				users = this->_currChannel->getUsers();
		std::map<User *, bool>::iterator	i;
		for (i = users.begin(); i != users.end(); ++i)
		{
			if (i->first->getFd() != this->_user.getFd())
				send(i->first->getFd(), response.c_str(), response.size(), 0);
		}
	}	
	else if (mode == MOD_ALL)
	{
		std::map<User*, bool>				users = this->_currChannel->getUsers();
		std::map<User *, bool>::iterator	i;
		for (i = users.begin(); i != users.end(); ++i)
			send(i->first->getFd(), response.c_str(), response.size(), 0);
	}	
	else
		send(this->_user.getFd(), response.c_str(), response.size(), 0);
}

/**
 * @brief Aux function to complete the response message depending of the given code
 * @param code passed as enum definition or int value, will be the key in the switch
 * @return std::string detail, the message to be appended to the response
 */
std::string	Command::composeResponse(int code)
{
	std::string			detail = "";
	std::stringstream	limit_str;
	if (this->_currChannel && this->_currChannel->getUsersLimit() > 0)
		limit_str << this->_currChannel->getUsersLimit();

	switch (code)
	{
		case ERR_CUSTOM_CHANNEL:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_errorMsg + "\r\n";
			break;
		case RPL_ENDOFWHO:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :End of /WHO list.\r\n";
			break;
		case RPL_CHANNELMODEIS:
			if (this->_currChannel->isOp(this->_user))
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_currChannel->getModeStr() + " " + this->_currChannel->getPassword() + " " + limit_str.str() + "\r\n";
			else
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_currChannel->getModeStr() + " " + limit_str.str() + "\r\n";
			break;
		case RPL_CREATIONTIME:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_currChannel->getCreationTime() + "\r\n";
			break;
		case RPL_NOTOPIC:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :No topic is set\r\n";
			break;
		case RPL_TOPIC:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :" + this->_currChannel->getTopic() + "\r\n";
			break;
		case RPL_TOPICWHOTIME:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_currChannel->getTopicCreator() + " " + this->_currChannel->getTimeStamp() + "\r\n";
			break;
		case RPL_INVITING:
			detail = " " + this->_user.getNick() + " " + this->_splitCmd[1] + " " + this->_currChannel->getName() + "\r\n";
			break;
		case RPL_WHOREPLY:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_errorMsg;
			break;
		case RPL_NAMREPLY:
			detail = " " + this->_user.getNick() + " = " + this->_currChannel->getName() + " :" + this->_currChannel->getUsersChannelStr() + "\r\n";
			break;
		case RPL_ENDOFNAMES:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :End of /NAMES list\r\n";
			break;
		case ERR_NOSUCHNICK:
			detail = " " + this->_user.getNick() + " " + this->_errorMsg + " :No such nick/channel\r\n";
			break;
		case ERR_NOSUCHCHANNEL:
			detail = " " + this->_user.getNick() + " " + this->_splitCmd[1] + " :No such channel\r\n";
			break;
		case ERR_NORECIPIENT:
			detail = " " + this->_user.getNick() + " :No recipient given (" + this->_splitCmd[0] + ")\r\n";
			break;
		case ERR_NOTEXTTOSEND:
			detail = " " + this->_user.getNick() + " :No text to send\r\n";
			break;
		case ERR_NONICKNAMEGIVEN:
			if (this->_user.getNick().empty())
				detail = " * :No nickname given\r\n";
			else
				detail = " " + this->_user.getNick() + " :No nickname given\r\n";
			break;
		case ERR_ERRONEUSNICKNAME:
			if (this->_user.getNick().empty())
				detail = " * " + this->_splitCmd[1] + " :Erroneous nickname\r\n";
			else
				detail = " " + this->_user.getNick() + " " + this->_splitCmd[1] + " :Erroneous nickname\r\n";
			break;
		case ERR_NICKNAMEINUSE:
			if (this->_user.getNick().empty())
				detail = " * " + this->_splitCmd[1] + " :Nickname is already in use\r\n";
			else
				detail = " " + this->_user.getNick() + " " + this->_splitCmd[1] + " :Nickname is already in use\r\n";
			break;
		case ERR_USERNOTINCHANNEL:
			if (!this->_errorMsg.empty())
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_errorMsg + " :User is not in channel\r\n";
			else
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_splitCmd[2] + " :They aren't on that channel\r\n";
			break;
		case ERR_NOTONCHANNEL:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :You're not on that channel\r\n";
			break;
		case ERR_USERONCHANNEL:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_splitCmd[1] + " :is already on channel\r\n";
			break;
		case ERR_NOTREGISTERED:
			detail = " * :You have not registered\r\n";
			break ;
		case ERR_NEEDMOREPARAMS:
			if (!this->_errorMsg.empty())
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_splitCmd[0] + this->_errorMsg + " :Not enough parameters\r\n";
			else if (this->_currChannel)
				detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " " + this->_splitCmd[0] + " :Not enough parameters\r\n";
			else	
				detail = " " + this->_user.getNick() + " " + this->_splitCmd[0] + " :Not enough parameters\r\n";
			break;
		case ERR_ALREADYREGISTERED:
			detail = " " + this->_user.getNick() + " :You may not reregister\r\n";
			break;
		case ERR_PASSWDMISMATCH:
			detail = " * :Password incorrect\r\n";
			break;
		case ERR_KEYSET:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :Channel key already set\r\n";;
			break;
		case ERR_CHANNELISFULL:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :Cannot join channel (+l)\r\n";
			break;
		case ERR_INVITEONLYCHAN:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :Cannot join channel (+i)\r\n";
			break;
		case ERR_BADCHANNELKEY:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :Cannot join channel (+k)\r\n";
			break;
		case ERR_BADCHANMASK:
			detail = " " + this->_errorMsg + " :Bad Channel Mask\r\n";
			break;
		case ERR_CHANOPRIVSNEEDED:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :You're not channel operator\r\n";
			break;
		case ERR_UMODEUNKNOWNFLAG:
			detail = " " + this->_user.getNick() + " " + this->_currChannel->getName() + " :Unknown MODE flag: " + this->_unknowFlags + "\r\n";
			break;
		default:
			break;
	}
	return (detail);
}
