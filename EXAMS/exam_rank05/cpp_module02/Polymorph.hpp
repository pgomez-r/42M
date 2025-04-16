#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class Polymorph : public ASpell{
	public:
		Polymorph();
		~Polymorph();
		ASpell *clone() const;
};
