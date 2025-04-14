#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *ptr)
{
	if(ptr)
		map[ptr->getName()] = ptr->clone();
}
void SpellBook::forgetSpell(const std::string &name)
{
	if(map.find(name) != map.end())
		map.erase(map.find(name));
}

ASpell *SpellBook::createSpell(const std::string &name)
{
	ASpell *aux = NULL;
	if(map.find(name) != map.end())
		aux = this->map[name];
	return(aux);
}
