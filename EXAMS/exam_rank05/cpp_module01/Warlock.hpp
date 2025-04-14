#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
	private:
			std::string _name;
			std::string _title;
			Warlock();
			Warlock(const Warlock &data);
			Warlock &operator=(const Warlock &data);
			std::map<std::string,ASpell *> map;
			
	public:
			Warlock(const std::string &name,const std::string &title);
			const std::string &getName() const;
			const std::string &getTitle() const;
			void setTitle(const std::string &name);
			~Warlock();
			void introduce() const;
			void learnSpell(ASpell *ptr);
			void forgetSpell(std::string name);
			void launchSpell(std::string name,ATarget &data);
};
