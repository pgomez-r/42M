#ifndef User_HPP
#define User_HPP

#include "ft_irc.hpp"

class Channel;
class User 
{
	private:
		int 					_fd;
		std::string				_buffer;
		bool					_authenticated;
		bool					_logged;
		bool					_hexChatClient;
		std::string				_nickName;
		std::string				_userName;
		std::string 			_realName;
		std::string				_host;
		std::vector<Channel*>	_channelList;
	public:
		User();
		User(int fd);
		User(const User& rhs);
		User& operator=(const User& rhs);
		~User();
		//Get-set
		int 					getFd() const;
		bool 					getAuthenticated() const;
		void 					setAuthenticated(bool authenticated);
		std::string 			getNick() const;
		void 					setNick(std::string nick);
		std::string 			getUserName() const;
		void 					setUserName(std::string userName);
		std::string 			getRealName() const;
		void 					setRealName(std::string realName);
		bool					getHexClient() const;
		void					setHexClient(bool state);
		bool					getLoginStat() const;
		void					setLoginStat(bool stat);
		std::vector<Channel*>	getChannelList();
		std::string				getHost() const;
		//User methods
		void					addChannelToList(Channel *channel);
		void					delChannelFromList(Channel *channel);
		std::string				getHostName() const;
		std::string				bufferFilter(std::string readMsg);
};

std::ostream& operator<<(std::ostream& out, const User& user);

#endif