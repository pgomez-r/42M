#include "ft_irc.hpp"

std::ostream& operator<<(std::ostream& out, const Server& server)
{
	out  << "Server: " << server.getName() << std::endl;
	out << "Port: " << server.getPort() << std::endl;
	if(server.getIsRunning())
	{
		out << GRE << "Server is running" << RES << std::endl;
	}
	else
	{
		out << RED << "Server is not running" << RES << std::endl;
	}
	return out;
}

void Server::signalHandler(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
		throw std::runtime_error("Server stopped by signal");
}

/**
 * @brief Sends a message to the user with the registration process usage
 */
void Server::welcomeUser(int userFd)
{
	std::string msg;
	msg = "Wecolme to The Pollitas Server!\r\n";
	msg.append("IF YOU ARE USING HEXCHAT CLIENT - IGNORE THESE INSTRUCTIONS -\r\n");
	msg.append("Otherwise, follow this registration process usage:\r\n");
	msg.append("Message #1 - \"PASS <server_password>\" Message #2\"NICK <user_nick>\"\r\n");
	send(userFd, msg.c_str(), msg.length(), 0);
}

/**
 * @brief Auxiliary function to send a message from server to the user
 * (!) Uses the send() function from sys/socket.h
 * First, set the beginning of the message with the server name then append str received
 * @param userFd the user socket file descriptor
 * @param str the message to be sent
 */
void	Server::sendWarning(int userFd, std::string str)
{
	std::string	msg = ":" + this->_name + " :";
	msg.append(str);
	send(userFd, msg.c_str(), msg.length(), 0);
}

/**
 * @brief To communicate server-client when command is made
 * @param message message to send in HexChat format
 * @param source user that has made the command
 * @param target user to get the message (may be the same)
 */
void	Server::messageToClient(const std::string& message, User &source, User &target)
{
	std::string	command_msg;

	command_msg.clear();
	command_msg = ":" + source.getNick() + "!" + source.getUserName() + " " + message + "\r\n";
	send(target.getFd(), command_msg.c_str(), command_msg.size(), 0);

}

/**
 * @brief Aux function to properly delete a user from the server: getting its pollfd
 *	out of the poll vector, deleting the object and closing the socket
 * (!) It is important to keep this order to avoid unexpected behaviors
 * @param i vector iterator to find the user's pollfd strucut to be deleted
 * @param socketFd the user socket file descriptor
 */
void	Server::deleteUser(int socketFd)
{
	std::vector<struct pollfd>::iterator i = this->_fds.begin();

	while (i != this->_fds.end())
	{
		if (i->fd == socketFd)
		{
			_fds.erase(i);
			break ;
		}
		i++;
	}
	delete (this->_users[socketFd]);
	this->_users.erase(socketFd);
	close(socketFd);
}

/**
 * @brief end the server, close all fds if still opened including the server fd
 */
void Server::stop()
{
	std::vector<int>				userFds;
	std::map<int, User*>::iterator	it;

	for (it = _users.begin(); it != _users.end(); ++it)
		userFds.push_back(it->first);
	for (size_t i = 0; i < userFds.size(); ++i)
		deleteUser(userFds[i]);
	this->removeChannels();
	close(_serverFd);
	_fds.clear();
	_users.clear();
	_channels.clear();
	_channelsMap.clear();
	this->_isRunning = false;
	std::cout << "Server stopped" << std::endl;
}

/**
 * @brief Returns a pointer to the user object with the given nick
 */
User	*Server::getUserByNick(std::string nick)
{
	User	*user_ptr = NULL;
	std::map<int, User*>::iterator i = this->_users.begin();

	while (i != this->_users.end())
	{
		if (i->second->getNick() == nick)
		{
			user_ptr = i->second;
			break ;
		}
		i++;
	}
	return (user_ptr);
}

/**
 * @brief Returns a pointer to the user object with the given socket fd
 */
User	*Server::getUserByFd(int fd)
{
	User	*user_ptr = NULL;
	std::map<int, User*>::iterator i = this->_users.find(fd);

	if (i != this->_users.end())
		user_ptr = i->second;
	return (user_ptr);
}
