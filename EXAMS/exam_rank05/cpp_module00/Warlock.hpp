//#pragma once replaces ifndef - def - endif
#pragma once

#include <iostream>

class Warlock
{
	// Beside the attributes, we define not allowed constructors as private
	private:
			std::string _name;
			std::string _title;
			Warlock();
			Warlock(const Warlock &src);
			Warlock &operator=(const Warlock &src);
	public:
			Warlock(const std::string &name,const std::string &title);
			const std::string &getName() const;
			const std::string &getTitle() const;
			void setTitle(const std::string &name);
			~Warlock();
			void introduce() const;
};
