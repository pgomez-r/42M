#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

std::string ATarget::getType() const
{
	return (_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
