#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title){
	this->_name = name;
	this->_title = title;
	this->_book = new SpellBook();
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
	delete (this->_book);
	std::cout << this->_name << ": My job here is done!\n";
}

const std::string &Warlock::getName() const{
	return(this->_name);
}

const std::string &Warlock::getTitle() const{
	return(this->_title);
}

void Warlock::setTitle(const std::string &str){
	this->_title = str;
}

void Warlock::introduce() const{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n"; 
}

void Warlock::learnSpell(ASpell *spell){
	if(spell)
		this->_book->learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName){
	this->_book->forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target){
	if(this->_book->createSpell(spellName))
		this->_book->createSpell(spellName)->launchSpell(target);
}

