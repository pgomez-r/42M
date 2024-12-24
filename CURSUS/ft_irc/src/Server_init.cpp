#include "ft_irc.hpp"

Server::Server()
{
}

Server::Server(int port, std::string password)
{
	this->_port = port;
	this->_password = password;
	this->_name = "MyServer";
	this->_isRunning = false;
	this->_serverFd = -1;
	this->_message = "";
	this->_readMsg = true;
}

Server::~Server()
{
}

int	Server::getPort() const
{
	return (this->_port);
}

std::string	Server::getName() const
{
	return (this->_name);
}

bool	Server::getIsRunning() const
{
	return (this->_isRunning);
}

/**
 * @brief Getter to the server password, for future pass check
 */
const std::string	Server::getPassword() const
{
	return (this->_password);
}

/**
 * @brief Getter to the server channels vector;
 *	returns a reference to the vector so we can modify it
 */
std::vector<Channel *>	&Server::getChannels()
{
    return (_channels);
}

/**
 * @brief Getter to the server channels map;
 *	returns a reference to the vector so we can modify it
 */
std::map<std::string, Channel *>	&Server::getChannelsMap()
{
    return (_channelsMap);
}


void	Server::setReadMsg(bool state)
{
	this->_readMsg = state;
}
