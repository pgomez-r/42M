#pragma once

#include "ASpell.hpp"

class ASpell;
class Polymorph: public ASpell
{
	public:
			Polymorph();
			~Polymorph();
			ASpell *clone() const;
};
