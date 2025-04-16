#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class BrickWall : public ATarget{
	public:
		BrickWall();
		~BrickWall();
		ATarget *clone() const;
};
