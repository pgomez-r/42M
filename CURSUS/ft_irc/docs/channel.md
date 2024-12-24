# Channel

Para implementar channel de primeras tenemos que saber que atributos necesitaremos para poder hacerlo de manera correcta. Estos atributos de momento van a ser:
* bool        _isPrivate;
* size_t      _maxUsers;
* std::string _channelName;
* std::string _channelPass;
* std::string _topic;
* std::map<User&, bool> _users;
* std::vector<User> _channelUsers;
* std::vector<User> _channelOp;