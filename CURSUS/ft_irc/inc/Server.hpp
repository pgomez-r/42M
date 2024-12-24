
#ifndef SERVER_HPP
#define SERVER_HPP

#include "ft_irc.hpp"

class Channel;
class User;

class Server
{
	private:
		int								_port;
		std::string						_password;
		std::string						_name;
		bool							_isRunning;
		int								_serverFd;
		std::string						_message;
		bool							_readMsg;
		std::vector<Channel *>			_channels;
		std::map<std::string, Channel*>	_channelsMap;
		std::map<int, User *>			_users;
		std::vector<struct pollfd> 		_fds;
	
	public:
		Server();
		Server(int port, std::string password);
		~Server();
		
		//Get-set
		int 							getPort() const;
		std::string 					getName() const;
		bool 							getIsRunning() const;
		User							*getUserByNick(std::string nick);
		User							*getUserByFd(int fd);
		const std::string				getPassword() const;
		std::vector<Channel*>			&getChannels();
    	std::map<std::string, Channel*>	&getChannelsMap();
		Channel							*getChannelByName(std::string name);
		void							setReadMsg(bool state);
		//Server engine methods
		static void						signalHandler(int signal);
		void 							prepareSocket();
		void 							start();
		void 							run();
		void 							stop();
		void 							newConnection();
		void							deleteUser(int socketFd);
		void							removeChannels();
		//Message-user handle methods
		void							welcomeUser(int userFd);
		void							sendWarning(int userFd, std::string str);
		void							msgHandler(int socketFd);
		void							messageToClient(const std::string& message, User &source, User &target);
		//Channel methods
		void							createChannel(const std::string& name);
		void							addUserToChannel(const std::string& channelName, User& user);
		bool 							channelExists(const std::string& name);
};

std::ostream& operator<<(std::ostream& out, const Server& server);

#endif
