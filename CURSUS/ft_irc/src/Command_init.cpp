#include "ft_irc.hpp"

/**
 * @brief Command constructor
 * @param socketFd the socket file descriptor - stored just in case, not sure yet if needed
 * @param msg the message to be checked - won't need this when we implement User_buffer
 * @param user reference to the user that sent the message, so we can use its methods
 * @param server reference to the server, so we can use its methods
 */
Command::Command(int socketFd, const std::string msg, User &user, Server &server)
	: _socketFd(socketFd), _msg(msg), _user(user), _server(server)
{
	this->_currChannel = NULL;
	this->_errorMsg = "";
	this->_unknowFlags = "";
	this->_splitCmd = ft_split(msg);
	this->_paramCount = 0;
	this->_initCommands();
}

/**
 * @brief Initialize the commands array with the possible commands
 * (!) Has to be updated when new commands are added to enum and match its order
 */
void	Command::_initCommands()
{
	this->_commands[0] = "CAP LS";
	this->_commands[1] = "PASS";
	this->_commands[2] = "USER";
	this->_commands[3] = "NICK";
	this->_commands[4] = "JOIN";
	this->_commands[5] = "QUIT";
	this->_commands[6] = "PRIVMSG";
	this->_commands[7] = "KICK";
	this->_commands[8] = "INVITE";
	this->_commands[9] = "TOPIC";
	this->_commands[10] = "MODE";
	this->_commands[11] = "WHO";
}

/**
 * @brief Command destructor
 */
Command::~Command()
{
}

/**
 * @brief Aux function to check if the message is a valid command, then calls runCmd
 * @param userFd the user file descriptor - propably won't need it later when user class is more developed
 * @return bool just in case can use it to runs check or conditions later
 *	true if the message is a valid command, false otherwise
 */
bool Command::checkCmd(int userFd)
{
	for (int i = 0; i < TOTAL; i++)
	{
		if (this->_msg.find(_commands[i]) == 0)
		{
			runCmd(userFd, i);
			return (true);
		}
	}
	return (false);
}

/**
 * @brief Run the command if found; each case calls the corresponding command method
 * @param userFd the user file descriptor
 * @param key the command key
 */
void	Command::runCmd(int userFd, int key)
{
	(void)userFd;
	switch (key)
	{
		case CAPLS:
			this->_user.setHexClient(true);
			break;
		case PASS:
			cmdPass();
			break;
		case USER:
			cmdUser();
			break;
		case NICK:
			cmdNick();
			break;
		case JOIN:
			cmdJoin();
			break;
		case QUIT:
			commandQuit();
			break;
		case PRIVMSG:
			cmdPrivmsg();
			break;
		case KICK:
			commandKick();
			break;
		case INVITE:
			commandInvite();
			break;
		case TOPIC:
			commandTopic();
			break;
		case MODE:
			cmdMode();
			break;
		case WHO:
			cmdWho();
			break;
		default:
			break;
	}
}

/**
 * @brief Aux function to kick the user from the server when trying to use a command before authentication
 *  - sends a message to the userm a log to the server and call server.deleteUser()
 */
void	Command::kickNonAuthenticatedUser(int userFd)
{
	std::cout << "User with socket fd " << userFd << " tried to use a command before authentication" << std::endl;
	this->sendResponse(ERR_NOTREGISTERED, MOD_USER, 0);
	this->_server.deleteUser(userFd);
	std::cout << RED << "User kicked and socket closed" << RES << std::endl;
}

/**
 * @brief take the message and split it into a vector of strings
 * 
 * @param msg 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Command::splitMessage(const std::string &msg, char delim)
{
	std::vector<std::string> args;
	std::string word;
	std::stringstream ss(msg);
	while (getline(ss, word, delim))
	{
		if(!word.empty())
			args.push_back(word);
	}
	return args;
}
