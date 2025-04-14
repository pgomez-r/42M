#pragma once

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
			std::string _name;
			std::string _effects;
	public:
			ASpell();
			ASpell(const ASpell &data);
			ASpell &operator=(const ASpell &data);
			virtual ~ASpell();
			ASpell(const std::string &name,const std::string &effects);
			const std::string &getName() const;
			const std::string &getEffects() const;
			virtual ASpell *clone() const = 0;
			void launch(const ATarget &data)const ;
};
