#include "ft_irc.hpp"

/*-----------------------[CHECK METHODS]------------------------*/
bool Channel::isUserInChannel(User& user)
{
	if (this->_usersMap.find(&user) != this->_usersMap.end())
		return (true);
	return (false);
}

/**
 * @brief Check if a user is administrator in the current channel
 * - Creates an iterator which finds an aim to the user passed as argument
 * - Then checks (if the user exists in list) if the user is op or not
 */
bool Channel::isOp(User& user) const
{
	std::map<User *, bool>::const_iterator i;

	i = this->_usersMap.find(&user);
	if (i != this->_usersMap.end() && i->second == true)
		return (true);
	return (false);
}

/**
 * @brief Check if the channel is full before a new user can join
 * (!) IF userLimit == -1 NO USERS LIMIT
 */
bool Channel::channelIsFull()
{
	if (this->_usersLimit == -1)
		return false;
	if (this->_usersMap.size() >= static_cast<size_t>(this->_usersLimit))
		return true;
	return false;
}
/*-----------------------[METHODS]------------------------*/
/**
 * @brief Add a user to a channel
 */
void Channel::addUserChannel(User& user)
{
	this->_usersInChannel++;
	this->_usersMap[&user] = false;
	std::string msg = ":" + user.getNick() + "!" + user.getUserName() + "@" + user.getHost() + " JOIN :" + this->getName() + "\n";
	send(user.getFd(), msg.c_str(), msg.length(), 0);
}

/**
 * @brief Remove a user from the channel
 * @param user the user to be removed
 */
void Channel::removeUserChannel(User& user)
{
	std::map<User *, bool>::iterator i;

	i = this->_usersMap.find(&user);
	if (i != this->_usersMap.end())
	{	
		this->_usersMap.erase(i);
		this->_usersInChannel--;
	}
}

/**
 * @brief add a user to the op vector after checking if the user is already an op
 * (!) Changed, since no op_vector if user is in channel and not op, set bool TRUE
 * Now is more like a setOpUser than addOp since it does not add to any vector
 * @param user 
 */
void Channel::addOpChannel(User& user)
{
	std::map <User*, bool>::iterator	aux;

	aux = this->_usersMap.find(&user);
	aux->second = true;
}

/**
 * @brief remove user from the op vector after checking if the user is already an op
 */
void Channel::deleteOpChannel(User& user)
{
	std::map <User*, bool>::iterator	aux;

	aux = this->_usersMap.find(&user);
	aux->second = false;
}

/**
 * @brief Broadcast a message to all users in the channel except the one who sent the message
 * @param mode 0 to send all user but sender, 1 to send to all (including the sender)
 * @param message the text message to be sent
 * @param command_msg the message to be sent formatted as irc protocol needs
 * @param userFd the user file descriptor to avoid sending the message to the sender
 */
void Channel::broadcastMessage(const std::string& message, User &sender, int mode)
{
	std::map<User *, bool>::iterator	i;
	std::string							command_msg;

	command_msg.clear();
	command_msg = ":" + sender.getNick() + "!" + sender.getUserName() + "@" + sender.getHost() + " " + message + "\r\n";
	for (i = this->_usersMap.begin(); i != this->_usersMap.end(); ++i)
	{
		if (i->first->getFd() == sender.getFd() && mode == 0)
			continue ;
		send(i->first->getFd(), command_msg.c_str(), command_msg.size(), 0);
	}
}

/**
 * @brief Aux function to update channel topic when command is executed
 * 	Sets the new topic and saves it timestamp and creator
 */
void	Channel::updateTopic(const std::string &topic, const std::string &userNick)
{
	std::stringstream	time_string;
	std::time_t			now_time = std::time(NULL);
	
	this->setTopic(topic);
	this->_topicCreator = userNick;
	time_string << now_time;
	this->_topicTimeStamp = time_string.str();
}

/**
 * @brief Aux function to update channel mode when command is executed
 * 	Checks if the mode is being added (op == 0)or removed (op == 1)
 * 	and updates the mode string
 */
void Channel::updateMode(char mode, int op)
{
	if (op == 0)
	{
		if (this->_modeStr.empty())
			this->_modeStr = "+";
		if (this->_modeStr.find(mode) != std::string::npos)
			return;
		this->_modeStr += mode;
	}
	else
	{
		if (this->_modeStr.find(mode) == std::string::npos)
			return;
		this->_modeStr.erase(this->_modeStr.find(mode), 1);
		if (this->_modeStr.size() == 1 && this->_modeStr[0] == '+')
			this->_modeStr = "";
	}
}

void Channel::setName(const std::string& name)
{
	this->_name = name;
}

void Channel::setTopic(const std::string& topic)
{
	this->_topic = topic;
}

void Channel::setInviteMode(const bool inviteMode)
{
	this->_inviteMode = inviteMode;
}

void Channel::setTopicMode(const bool topicMode)
{
	this->_topicMode = topicMode;
}

void Channel::setKeyMode(const bool keyMode)
{
	this->_keyMode = keyMode;
}

void Channel::setUsersInChannel(const int usersInChannel)
{
	this->_usersInChannel = usersInChannel;
}

void Channel::setUsersLimit(const int usersLimit)
{
	this->_usersLimit = usersLimit;
}

void Channel::setPassword(const std::string& password)
{
	this->_password = password;
}
