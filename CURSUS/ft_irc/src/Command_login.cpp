#include "ft_irc.hpp"

/**
 * @brief Command to check the password sent by the user
 * - First, check if already register (PASS can only be used at login)
 * - Then, check if enough params
 * - Finally, get and check password, if wrong - ERR_PASSWDMISMATCH (464)
 */
void	Command::cmdPass()
{
	if (this->_user.getAuthenticated())
		return (this->sendResponse(ERR_ALREADYREGISTERED, MOD_USER, 0));
	if (this->_splitCmd.size() < 2)
	{
		this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0);
		this->_server.setReadMsg(false);
		return (this->_server.deleteUser(this->_user.getFd()));
	}
	std::string	pass;
	pass = this->_msg.substr(this->_msg.find("PASS") + 5);
	pass.erase(pass.find_last_not_of(" \n\r\t") + 1);
	if (pass != this->_server.getPassword())
	{
		std::cout << "New connection with socket fd " << this->_user.getFd() << " tried to login with wrong password" << std::endl;
		std::cout << RED << "Connection rejected and socket closed" << RES << std::endl;
		this->sendResponse(ERR_PASSWDMISMATCH, MOD_USER, 0);
		this->_server.setReadMsg(false);
		return (this->_server.deleteUser(this->_user.getFd()));
	}
	this->_user.setAuthenticated(true);
}

/**
 * @brief Command to set or change the user nickName
 *	- if the user is HexChat client and this is first connection message
 *		("NICK <nick>\nUSER <user> 0 * :<realname>\n") cmdUser is called
 *	- if the user is 'nc' client, the nickName is set as userName and realName (provisional)
 * (!) First check if user is already authenticated - if not, kick the user
 */
void	Command::cmdNick()
{
	if (!this->_user.getAuthenticated())
		return (kickNonAuthenticatedUser(this->_user.getFd()));

	if (this->_splitCmd.size() < 2)
	{
		this->sendResponse(ERR_NONICKNAMEGIVEN, MOD_USER, 0);
		if (!this->_user.getLoginStat())
		{
			this->_server.setReadMsg(false);
			this->_server.deleteUser(this->_user.getFd());
		}
		return ;
	}
	
	std::string	nick;
	nick = this->_msg.substr(5);
	nick.erase(nick.find_last_not_of(" \r\t\n") + 1);
	if (nick.find_first_of(" #:!@*") == 0 || std::isdigit(nick[0]))
	{
		this->sendResponse(ERR_ERRONEUSNICKNAME, MOD_USER, 0);
		if (!this->_user.getLoginStat())
		{
			this->_server.setReadMsg(false);
			this->_server.deleteUser(this->_user.getFd());
		}
		return ;
	}
	User *aux = this->_server.getUserByNick(nick);
	if (aux != NULL && this->_user.getNick() != nick)
	{
		this->sendResponse(ERR_NICKNAMEINUSE, MOD_USER, 0);
		if (!this->_user.getLoginStat())
		{
			this->_server.setReadMsg(false);
			this->_server.deleteUser(this->_user.getFd());
		}
		return ;
	}

	std::vector<Channel*>	user_channels = this->_user.getChannelList();
	if (!user_channels.empty())
	{
		for (size_t i = 0; i < user_channels.size(); ++i)
			user_channels[i]->broadcastMessage(this->_msg, this->_user, 1);
	}
	this->_user.setNick(nick);
	if (!this->_user.getHexClient())
	{
		this->_user.setUserName(nick);
		this->_user.setRealName(nick);
		this->_user.setLoginStat(true);
	}
}

/**
 * @brief Command to set the user userName and realName, it will always be sent
 *	at connection process, otherwise it will be treated as non-command message
 *	- if the user is HexChat client this is the nick-user message
 *		("NICK <nick>\nUSER <user> 0 * :<realname>\n")
 * (!) Need to check if user is already authenticated FIRST - if not, kick the user
 */
void Command::cmdUser()
{
	if (!this->_user.getAuthenticated())
		return (kickNonAuthenticatedUser(this->_user.getFd()));
	if (this->_user.getLoginStat())
		return (this->sendResponse(ERR_ALREADYREGISTERED, MOD_USER, 0));
	if (this->_splitCmd.size() < 2 || this->_splitCmd[1].size() == 0)
		return (this->sendResponse(ERR_NEEDMOREPARAMS, MOD_USER, 0));

	std::string	user = this->_splitCmd[1];
	user.erase(user.find_last_not_of(" \r\t\n") + 1);
	this->_user.setUserName(user);

	std::string	real_name = "";
	for (size_t i = 4; i < this->_splitCmd.size(); i++)
	{
		real_name.append(this->_splitCmd[i]);
		real_name.append(" ");
	}
	real_name.erase(real_name.find_last_not_of(" \r\t\n") + 1);
	if (real_name[0] == ':')
		real_name.erase(0, 1);
	this->_user.setRealName(real_name);
	this->_user.setLoginStat(true);
}
