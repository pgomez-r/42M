#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* targetName)
{
	if (_TargetBook.find(targetName->getType()) == _TargetBook.end())
		_TargetBook[targetName->getType()] = targetName->clone();
}

void TargetGenerator::forgetTargetType(std::string const & targetName)
{
	if (_TargetBook.find(targetName) != _TargetBook.end())
		_TargetBook.erase(_TargetBook.find(targetName));
}

ATarget* TargetGenerator::createTarget(std::string const &targetName)
{
	ATarget *target = NULL;
	if (_TargetBook.find(targetName) != _TargetBook.end()){
		target = _TargetBook[targetName];}
	return (target);
}