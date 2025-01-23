
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon", 25 , 5)
{
	std::cout << "Presidential Pardon default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	std::cout << "Presidential Pardon custom constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon " << getName() << " destructor called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Presidential copy consturctor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	(void)src;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &officer) const
{
	if (checkSigned() && officer.getGrade() <= getExecGrade())
	{
		std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw(FormNotSigned());
}
