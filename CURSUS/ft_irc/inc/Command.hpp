#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "ft_irc.hpp"

class	User;

enum command
{
	CAPLS,
	PASS,
	USER,
	NICK,
	JOIN,
	QUIT,
	PRIVMSG,
	KICK,
	INVITE,
	TOPIC,
	MODE,
	WHO,
	TOTAL
};

class Command
{
    private:
		int							_socketFd;
		std::string					_msg;
		std::string					_errorMsg;
		std::string					_unknowFlags;
		std::string					_commands[TOTAL];
		void						_initCommands();
		User						&_user;
		Server						&_server;
		Channel						*_currChannel;
		std::vector<std::string>	_splitCmd;
		std::vector<std::string>	_modes;
		std::vector<std::string>	_params;
		size_t 						_paramCount;
    public:
		Command(int socketFd, const std::string msg, User &user, Server &server);
		~Command();
		//Aux Methods	
		bool 						checkCmd(int userFd);
		void						runCmd(int userFd, int key);
		void						kickNonAuthenticatedUser(int userFd);
		void						sendResponse(int code, int mode, int fd);
		std::string					composeResponse(int code);
		std::vector<std::string>	splitMessage(const std::string &msg, char delim);
		void 						execModes(const char sign, const char mode);
		//Commands methods
		void 						cmdNick();
		void 						cmdPass();
		void 						cmdUser();
		void 						cmdPrivmsg();
		void 						cmdJoin();
		void 						commandKick();
		void 						commandInvite();
		void 						commandQuit();
		void 						commandTopic();
		void 						cmdMode();
		void						cmdWho();
};

#endif
