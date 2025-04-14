#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
			std::map<std::string,ATarget *> map;
			TargetGenerator &operator=(const TargetGenerator &data);
			TargetGenerator(const TargetGenerator &data);			
	public:
			TargetGenerator();
			~TargetGenerator();
			void learnTargetType(ATarget *ptr);
			void forgetTargetType(const std::string &name);
			ATarget *createTarget(const std::string &name);
};
