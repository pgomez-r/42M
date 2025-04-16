#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::~ASpell(){
}

ASpell::ASpell(const std::string &name, const std::string &effects){
	this->_name = name;
	this->_effects = effects;
}

ASpell::ASpell(const ASpell &src){
	*this = src;
}

ASpell &ASpell::operator=(const ASpell &src){
	this->_name = src._name;
	this->_effects = src._effects;
	return(*this);
}

const std::string &ASpell::getName() const{
	return(this->_name);
}
const std::string &ASpell::getEffects() const{
	return(this->_effects);
}
void ASpell::launchSpell(const ATarget &target) const{
	target.getHitBySpell(*this);
}
