#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(const ATarget &data)
{
	*this = data;
}
ATarget &ATarget::operator=(const ATarget &data)
{
	this->_type = data._type;
	return(*this);
}
ATarget::ATarget(const std::string &type)
{
	this->_type = type;
}
const std::string &ATarget::getType() const {return(this->_type);}

ATarget::~ATarget(){}

void ATarget::getHitBySpell(const ASpell &data) const
{
	std::cout << _type << " has been " << data.getEffects() << "!" << std::endl;
}
