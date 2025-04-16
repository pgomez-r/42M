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

