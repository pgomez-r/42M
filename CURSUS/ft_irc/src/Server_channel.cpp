#include "ft_irc.hpp"

void Server::createChannel(const std::string& name)
{
	Channel *newChannel = new Channel(name);
	this->_channels.push_back(newChannel);
	this->_channelsMap[name] = newChannel;
}

void Server::addUserToChannel(const std::string& channelName, User& user)
{
	for (size_t i = 0; i < this->_channels.size(); i++)
	{
		if (this->_channels[i]->getName() == channelName)
		{
			this->_channels[i]->addUserChannel(user);
			return;
		}
	}
}

/**
 * @brief Remove all channel objects (allocated with new) from _channels vector
 */
void Server::removeChannels()
{
	for (size_t i = 0; i < this->_channels.size(); i++)
		delete this->_channels[i];
}

bool Server::channelExists(const std::string& name)
{
	for (size_t i = 0; i < this->_channels.size(); i++)
	{
		if (this->_channels[i]->getName() == name)
			return (true);
	}
	return (false);
}

/**
 * @brief Returns a [pointer to a] channel by its name if found, NULL otherwise
 */
Channel	*Server::getChannelByName(std::string name)
{
	Channel	*channel_ptr = NULL;
	std::map<std::string, Channel*>::iterator i = this->_channelsMap.find(name);

	if (i != this->_channelsMap.end())
		channel_ptr = i->second;
	return (channel_ptr);
}
