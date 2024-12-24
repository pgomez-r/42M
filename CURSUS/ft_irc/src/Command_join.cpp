
#include "ft_irc.hpp"

/**
 * @brief Command to join a channel
 * 	- if the user is not authenticated, kick the user
 * 	- split the message into the channel name and key
 * 	- if the channel name is empty or does not start with #, send an error message
 * 	- check if the channel exists
 *	- if the channel does not exist, create it and add the user as operator
 *	- if the channel exists, add the user to the channel
 */
void Command::cmdJoin()
{
	if (!this->_user.getAuthenticated())
		return (kickNonAuthenticatedUser(this->_user.getFd()));
	if (this->_splitCmd.size() < 2)
		return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));

	std::vector<std::string> args = splitMessage(this->_msg, ' ');
	std::vector<std::string> channels = splitMessage(args[1], ',');
	std::vector<std::string> keys = (args.size() > 2) ? splitMessage(args[2], ',') : std::vector<std::string>();

	for (size_t i = 0; i < channels.size(); i++)
		channels[i].erase(channels[i].find_last_not_of(" \n\r\t") + 1);
	for (size_t i = 0; i < keys.size(); i++)
		keys[i].erase(keys[i].find_last_not_of(" \n\r\t") + 1);
	for (size_t i = 0; i < channels.size(); i++)
	{
		std::string channelName = channels[i];
		if (!channelName.empty())
			channelName.erase(channelName.find_last_not_of(" \n\r\t") + 1);
	
		this->_currChannel = this->_server.getChannelByName(channelName);
		if (channelName.empty() || channelName[0] != '#' || channelName.size() < 2 || channelName.size() > 50)
		{
			this->_errorMsg = channelName;
			this->sendResponse(ERR_BADCHANMASK, MOD_USER, 0);
			continue ;
		}
		if (!this->_currChannel)
		{
			this->_server.createChannel(channelName);
			this->_currChannel = this->_server.getChannelByName(channelName);
			this->_currChannel->addUserChannel(this->_user);
			this->_currChannel->addOpChannel(this->_user);
			this->_user.addChannelToList(this->_currChannel);
			std::string topic = this->_currChannel->getTopic();
			this->sendResponse(RPL_NAMREPLY, MOD_USER, 0);
			this->sendResponse(RPL_ENDOFNAMES, MOD_USER, 0);
		}
		else
		{
			if (this->_currChannel->isUserInChannel(this->_user))
				continue;
			if (this->_currChannel->getInviteMode())
			{
				this->sendResponse(ERR_INVITEONLYCHAN, MOD_USER, 0);
				continue;
			}
			if (this->_currChannel->getKeyMode() && (keys.size() <= i || keys[i] != this->_currChannel->getPassword()))
			{
				this->sendResponse(ERR_BADCHANNELKEY, MOD_USER, 0);
				continue;
			}
			if (this->_currChannel->channelIsFull())
			{
				this->sendResponse(ERR_CHANNELISFULL, MOD_USER, 0);
				continue;
			}
			this->_currChannel->addUserChannel(this->_user);
			this->_user.addChannelToList(this->_currChannel);
			std::string msg = "JOIN " + channelName;
			this->_currChannel->broadcastMessage(msg, this->_user, 0);
			std::string topic = this->_currChannel->getTopic();
			if (!topic.empty())
			{
				this->sendResponse(RPL_TOPIC, MOD_USER, 0);
				this->sendResponse(RPL_TOPICWHOTIME, MOD_USER, 0);
			}
			this->sendResponse(RPL_NAMREPLY, MOD_USER, 0);
			this->sendResponse(RPL_ENDOFNAMES, MOD_USER, 0);
		}
	}
}

/**
 * @brief Command WHO, currently just using to handle informartion about a Channel
 * 	Otherwise, the command silenlty gets ignored
 */
void	Command::cmdWho()
{
	if (!this->_user.getAuthenticated())
		return (kickNonAuthenticatedUser(this->_user.getFd()));
	if (this->_splitCmd.size() != 2 || (this->_splitCmd.size() == 2 && this->_splitCmd[1][0] != '#'))
		return;
	
	std::string	channel_name = this->_splitCmd[1];
	channel_name.erase(channel_name.find_last_not_of(" \n\r\t") + 1);
	this->_currChannel = this->_server.getChannelByName(channel_name);
	if (!this->_currChannel || this->_currChannel->getUsersInChannel() < 1)
		return (this->sendResponse(ERR_NOSUCHCHANNEL, MOD_USER, 0));

	std::map<User*, bool>			users = this->_currChannel->getUsers();
	std::map<User*, bool>::iterator	i = users.begin();
	while (i != users.end())
	{
		User* curr_user = i->first;
		this->_errorMsg =  curr_user->getUserName() + " " + curr_user->getHost() + " " + this->_server.getName() + " " + curr_user->getNick() + " H :0 " + curr_user->getRealName() + "\r\n";
		this->sendResponse(RPL_WHOREPLY, MOD_USER, 0);
		i++;
	}
	this->sendResponse(RPL_ENDOFWHO, MOD_USER, 0);
}
