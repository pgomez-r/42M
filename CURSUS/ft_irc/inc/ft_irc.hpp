#ifndef FT_IRC_HPP
#define FT_IRC_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <signal.h>
#include <exception>
#include <fcntl.h>
#include <arpa/inet.h>
#include <ctime>
#include <algorithm>

#include "User.hpp"
#include "Channel.hpp"
#include "Server.hpp"
#include "Command.hpp"

#define RED		"\033[31m"
#define GRE		"\033[32m"
#define YEL		"\033[33m"
#define BLU		"\033[34m"
#define RES 	"\033[0m"
#define	TIMEOUT	30000

const int MAX_CLIENTS = 10;
const int BUFF_SIZE = 1024;

/*Errors and respones enum*/

enum response
{
	MOD_USER = 0,
	MOD_CAST = 1,
	MOD_ALL = 2,
	ERR_CUSTOM_CHANNEL = 142,
	RPL_ENDOFWHO = 315,
	RPL_CHANNELMODEIS = 324,
	RPL_CREATIONTIME = 329,
	RPL_NOTOPIC = 331,
	RPL_TOPIC = 332,
	RPL_TOPICWHOTIME = 333,
	RPL_INVITING = 341,
	RPL_WHOREPLY = 352,
	RPL_NAMREPLY = 353,
	RPL_ENDOFNAMES = 366,
	ERR_NOSUCHNICK = 401,
	ERR_NOSUCHCHANNEL = 403,
	ERR_NORECIPIENT = 411,
	ERR_NOTEXTTOSEND = 412,
	ERR_NONICKNAMEGIVEN = 431,
	ERR_ERRONEUSNICKNAME = 432,
	ERR_NICKNAMEINUSE = 433,
	ERR_USERNOTINCHANNEL = 441,
	ERR_NOTONCHANNEL = 442,
	ERR_USERONCHANNEL = 443,
	ERR_NOTREGISTERED = 451,
	ERR_NEEDMOREPARAMS = 461,
	ERR_ALREADYREGISTERED = 462,
	ERR_PASSWDMISMATCH = 464,
	ERR_KEYSET = 467,
	ERR_CHANNELISFULL = 471,
	ERR_INVITEONLYCHAN = 473,
	ERR_BADCHANNELKEY = 475,
	ERR_BADCHANMASK = 476,
	ERR_CHANOPRIVSNEEDED = 482,
	ERR_UMODEUNKNOWNFLAG = 501
	
};

/*Utils.cpp functions*/
bool						readFromSocket(int socketFd, std::string &store);
std::vector<std::string>	ft_split(std::string message);
std::string 				toString(int num);
bool 						isOnlyDigits(const std::string& str);

#endif