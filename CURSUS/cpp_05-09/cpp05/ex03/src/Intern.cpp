
#include "Intern.hpp"

Intern::Intern()
{
	this->_formNames[0] = "presidential pardon";
	this->_formNames[1] = "robotomy request";
	this->_formNames[2] = "shrubbery creation";
	std::cout << "Intern default constructor called" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	for (int i = 0; i < 3; i++)
		this->_formNames[i] = src._formNames[i];
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 3; i++)
			this->_formNames[i] = src._formNames[i];
	}
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm	*formPtr = NULL;
	std::string	name = formName;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	name.erase(name.find_last_not_of(" \t\n\r") + 1);
	int	i = 0;
	while (i < 3 && this->_formNames[i] != name)
		i++;
	switch (i)
	{
		case 0:
			formPtr = new PresidentialPardonForm(formTarget);
			break ;
		case 1:
			formPtr = new RobotomyRequestForm(formTarget);
			break ;
		case 2:
			formPtr = new ShrubberyCreationForm(formTarget);
			break ;
		default:
			throw(notFoundForm());
			break;
	}
	return (formPtr);
}

const char *Intern::notFoundForm::what() const throw()
{
	return ("Error: Form name does not exist, cannot create form");
}