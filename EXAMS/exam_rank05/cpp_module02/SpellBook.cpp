#include "SpellBook.hpp"

SpellBook::SpellBook(){

}

SpellBook::~SpellBook(){

}

void SpellBook::learnSpell(ASpell *spell){
	if(spell)
		this->_book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string &spell){
	if(this->_book.find(spell) != this->_book.end())
		this->_book.erase(this->_book.find(spell));
}

ASpell* SpellBook::createSpell(const std::string &spell){
	ASpell *ptr = NULL;
	if(this->_book.find(spell) != this->_book.end())
		ptr = this->_book[spell];
	return(ptr);
}


