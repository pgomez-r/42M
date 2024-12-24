#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "ft_irc.hpp"

class Channel
{
	private:
		std::string				_name;
		std::string				_topic;
		std::map<User*, bool>	_usersMap;
		bool					_inviteMode;
		bool					_topicMode;
		bool					_keyMode;
		int						_usersInChannel;
		int						_usersLimit;
		std::string				_password;
		std::string 			_topicTimeStamp;
    	std::string 			_topicCreator;
		std::string				_modeStr;
		std::string				_creationTime;
	
	public:
		Channel();
		Channel(const std::string& name);
		Channel(const Channel &rhs);
		~Channel();
		//Getters
		Channel& operator=(const Channel &rhs);
		const std::string&				getName() const;
		const std::string&				getTopic() const;
		const std::string&				getTimeStamp() const;
		const std::string&				getTopicCreator() const;
		const std::string				getModeStr() const;
		const std::string				getUsersChannelStr() const;
		const std::map<User*, bool>		&getUsers() const;
		bool							getInviteMode() const;
		bool							getTopicMode() const;
		bool							getKeyMode() const;
		int								getUsersInChannel() const;
		int								getUsersLimit() const;
		const std::string&				getPassword() const;
		const std::string				getCurrentTime() const;
		const std::string				getCreationTime() const;
		//Setters
		void							setName(const std::string& name);
		void							setTopic(const std::string& topic);
		void							setInviteMode(const bool inviteMode);
		void							setTopicMode(const bool topicMode);
		void							setKeyMode(const bool keyMode);
		void							setUsersInChannel(const int usersInChannel);
		void							setUsersLimit(const int usersLimit);
		void							setPassword(const std::string& password);
		//Check methods
		bool							isUserInChannel(User& user);
		bool							isOp(User& user) const;
		bool							channelIsFull();
		//Channel methods
		void							addUserChannel(User& user);
		void							removeUserChannel(User& user);
		void							broadcastMessage(const std::string& message, User &sender, int mode);
		void							addOpChannel(User& user);
		void							deleteOpChannel(User& user);
		void							updateTopic(const std::string &topic, const std::string &userNick);
		void							updateMode(char mode, int op);
};

std::ostream& operator<<(std::ostream& out, const Channel& channel);

#endif
