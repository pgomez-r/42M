#pragma once

#include "ATarget.hpp"

class ATarget;
class Dummy: public ATarget
{
	public:
			Dummy();
			~Dummy();
			ATarget *clone() const;
};
