#pragma once

#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator{
	private:
		std::map<std::string,ATarget *> _book;
		TargetGenerator(const TargetGenerator &src);
		TargetGenerator &operator=(const TargetGenerator &src);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(const std::string &type);
		ATarget* createTarget(const std::string &target);
};

