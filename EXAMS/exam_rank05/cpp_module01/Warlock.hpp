#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock{
	private:
		Warlock();
		Warlock(const Warlock &src);
		Warlock &operator=(const Warlock &src);
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell *> _spellBook;
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &str);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget &target);
};

