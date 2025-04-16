#pragma once

#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook{
	private:
		std::map<std::string, ASpell*> _book;
		SpellBook(const SpellBook &src);
		SpellBook &operator=(const SpellBook &src);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spell);
		ASpell* createSpell(const std::string &spell);
};

