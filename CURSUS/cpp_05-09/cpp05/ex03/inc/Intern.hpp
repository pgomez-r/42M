#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern
{
	private:
		std::string	_formNames[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
	
		AForm *makeForm(std::string formName, std::string formTarget);
		class notFoundForm: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
