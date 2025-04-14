#pragma once

#include <iostream>

class Warlock
{
	private:
			std::string _name;
			std::string _title;
			Warlock();
			Warlock(const Warlock &data);
			Warlock &operator=(const Warlock &data);
	public:
			Warlock(const std::string &name,const std::string &title);
			const std::string &getName() const;
			const std::string &getTitle() const;
			void setTitle(const std::string &name);
			~Warlock();
			void introduce() const;
};
