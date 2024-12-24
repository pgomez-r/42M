#include "ft_irc.hpp"

/**
 * @brief Main program process: prepare server socket, run poll check loop, stop and clean exit
 */
void Server::start()
{
	prepareSocket();
	run();
	stop();
}

/**
 * @brief Set the server socket; open socket fd, non blocking, bind and listen in selected port;
 *	then its fd	gets to the vector of pollfd strutc
 * @param poll_fd the struct pollfd needed by poll() function, where all server and client sockets 
 *	will be stored to be checked for events later on
 */
void Server::prepareSocket()
{
	struct sockaddr_in server_addr;
	struct pollfd poll_fd;
	
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(this->_port);
	
	this->_serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_serverFd < 0)
	{
		perror("socket");
		return;
	}
	int opt = 1;
	if (setsockopt(this->_serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) < 0)
	{
		perror("setsockopt");
		close(this->_serverFd);
		return;
	}
	if (fcntl(this->_serverFd, F_SETFL, O_NONBLOCK) < 0)
	{
		perror("fcntl");
		close(this->_serverFd);
		return;
	}
	if (bind(this->_serverFd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("bind");
		close(this->_serverFd);
		return;
	}
	if (listen(this->_serverFd, SOMAXCONN) < 0)
	{
		perror("listen");
		close(this->_serverFd);
		return;
	}
	poll_fd.fd = this->_serverFd;
	poll_fd.events = POLLIN;
	poll_fd.revents = 0;
	_fds.push_back(poll_fd);
	this->_isRunning = true;
	std::cout << *this << std::endl;
}

/**
 * @brief Running loop that runs through all sockets file descriptors stored in
 *	pollfd vector, checking if there is any new event (revents & POLLIN)
 *	(!) The poll() function will block the program until there is a new event
 *	If the event happens in the server fd, it means that there is a new connection
 *	attemp - newConnection()
 *	Otherwise, there is a new event coming from a client fd - msgHandler()
 */
void	Server::run()
{
	while (this->_isRunning)
	{
		if ((poll(&_fds[0], _fds.size(), -1)) < 0)
			throw std::runtime_error("poll");
		for (size_t i = 0; i < _fds.size(); i++)
		{
			if (_fds[i].revents & POLLIN)
			{
				if (_fds[i].fd == _serverFd)
					newConnection();
				else
					msgHandler(_fds[i].fd);
			}
		}
	}
}

/**
 * @brief New connection is handled quite similar to the way the server is set; the
 *	socket fd is set to be non-blocking, the pollfd struct is created and push to the
 *	last position of the vector, but in this case we also create a new User object
 *	At the end, we send a welcome message -with usage instructions- to the client
 * @param new_pollfd the struct pollfd needed by poll() function, where all client sockets 
 *	will be stored to be checked for events during the program lifecycle
 */
void	Server::newConnection()
{
	sockaddr_in 		client_addr;
	socklen_t 			client_addr_len = sizeof(client_addr);
	int 				client_socket;
	int					error;
	struct pollfd		new_pollfd;

	client_socket = accept(_serverFd, (struct sockaddr *)&client_addr, &client_addr_len);
	if (client_socket < 0)
	{
		perror("accept");
		return ;
	}
	error = fcntl(client_socket, F_GETFL, 0);
	if (error == -1 || fcntl(client_socket, F_SETFL, error | O_NONBLOCK) == -1)
	{
		perror("fcntl");
		close(client_socket);
		return;
	}
	new_pollfd.fd = client_socket;
	new_pollfd.events = POLLIN | POLLOUT;
	new_pollfd.revents = 0;
	_fds.push_back(new_pollfd);
	_users[client_socket] = new User(client_socket);
	std::cout << GRE << "New connection established with socket fd " << client_socket << RES << std::endl;
	welcomeUser(client_socket);
}

/**
 * @brief This function handles the message -poll event- sent by the current socket
 *	(!) readFromSocket() is a helper function that reads the message from the socket
 *		and stores it in a string (buffer)
 * 		- if nothing has been read, it means that the client disconnected, so we delete the user
 *	(!) Command class is created to handle the message, check if it is a valid command and run it
 */
void	Server::msgHandler(int socketFd)
{
	this->_message.clear();
	this->_readMsg = true;
	if (!readFromSocket(socketFd, this->_message))
		return (deleteUser(socketFd));
	std::cout << "[CLIENT]->to->server raw message -> " << this->_message << std::endl;
	this->_message = this->getUserByFd(socketFd)->bufferFilter(this->_message);
	while (!this->_message.empty() && this->_readMsg)
	{
		std::string	cmd_msg = "";
		size_t		pos = this->_message.find("\r\n");
		if (pos != std::string::npos)
		{
			cmd_msg = this->_message.substr(0, pos);
			this->_message.erase(0, pos + 2);
			Command	cmd(socketFd, cmd_msg, *(this->_users[socketFd]), *(this));
			cmd.checkCmd(socketFd);
		}
		else
		{
			Command	cmd(socketFd, this->_message, *(this->_users[socketFd]), *(this));
			cmd.checkCmd(socketFd);
			this->_message.clear();
		}
	}
}
