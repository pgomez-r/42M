#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class Fwoosh : public ASpell{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell *clone() const;
};
