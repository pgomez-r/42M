#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){

}

TargetGenerator::~TargetGenerator(){

}

void TargetGenerator::learnTargetType(ATarget *target){
	if(target)
		this->_book[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &target){
	if(this->_book.find(target) != this->_book.end())
		this->_book.erase(this->_book.find(target));
}

ATarget* TargetGenerator::createTarget(const std::string &target){
	ATarget *ptr = NULL;
	if(this->_book.find(target) != this->_book.end())
		ptr = this->_book[target];
	return(ptr);
}


