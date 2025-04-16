#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title){
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
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
		this->_spellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellName){
	if(this->_spellBook.find(spellName) != this->_spellBook.end())
		this->_spellBook.erase(this->_spellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, const ATarget &target){
	if(this->_spellBook.find(spellName) != this->_spellBook.end())
		this->_spellBook[spellName]->launchSpell(target);
}

