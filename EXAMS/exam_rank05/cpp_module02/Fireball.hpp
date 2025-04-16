#pragma once

#include "ASpell.hpp"
#include <iostream>

class ASpell;

class Fireball : public ASpell{
	public:
		Fireball();
		~Fireball();
		ASpell *clone() const;
};
