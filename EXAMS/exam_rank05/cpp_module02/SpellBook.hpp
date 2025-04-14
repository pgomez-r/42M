#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
	private:
			std::map<std::string,ASpell *> map;
			SpellBook &operator=(const SpellBook &data);
			SpellBook(const SpellBook &data);			
	public:
			SpellBook();
			~SpellBook();
			void learnSpell(ASpell *ptr);
			void forgetSpell(const std::string &name);
			ASpell *createSpell(const std::string &name);
};
