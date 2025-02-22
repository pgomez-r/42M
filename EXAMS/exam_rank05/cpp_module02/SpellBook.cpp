#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell* spell)
{
	if (_SpellBook.find(spell->getName()) == _SpellBook.end())
	{
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName));
}

ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	ASpell* spell = NULL;
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		spell = _SpellBook[SpellName];
	return (spell);
}