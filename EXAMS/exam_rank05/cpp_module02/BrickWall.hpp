#pragma once

#include "ATarget.hpp"

class ATarget;
class BrickWall: public ATarget
{
	public:
			BrickWall();
			~BrickWall();
			ATarget *clone() const;
};
