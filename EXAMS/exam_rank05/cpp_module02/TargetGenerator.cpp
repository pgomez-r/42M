#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *ptr)
{
	if(ptr)
		map[ptr->getType()] = ptr->clone();
}
void TargetGenerator::forgetTargetType(const std::string &name)
{
	if(map.find(name) != map.end())
		map.erase(map.find(name));
}

ATarget *TargetGenerator::createTarget(const std::string &name)
{
	ATarget *aux = NULL;
	if(map.find(name) != map.end())
		aux = this->map[name];
	return(aux);
}
