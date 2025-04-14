#pragma once

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
			std::string _type;
	public:
			ATarget();
			ATarget(const ATarget &data);
			ATarget &operator=(const ATarget &data);
			virtual ~ATarget();
			ATarget(const std::string &type);
			const std::string &getType() const;
			virtual ATarget *clone() const = 0;
			void getHitBySpell(const ASpell &data) const ;
};
