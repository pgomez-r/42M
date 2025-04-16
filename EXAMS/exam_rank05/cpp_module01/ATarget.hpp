#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
	protected:
		std::string _type;
	public:
		ATarget();
		ATarget(const ATarget &src);
		ATarget &operator=(const ATarget &src);
		ATarget(const std::string &type);
		virtual ~ATarget();
		virtual ATarget *clone() const = 0; 
		const std::string &getType() const;
		void getHitBySpell(const ASpell &spell) const;
};
