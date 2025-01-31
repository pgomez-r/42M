#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy Request", 72 , 45)
{
	std::cout << "Robotomy Request default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	std::cout << "Robotomy Request custom constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request " << getName() << " destructor called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Robotomy Request copy consturctor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &officer) const
{
	if (!this->checkSigned())
		throw FormNotSigned();
	if (officer.getGrade() > this->getExecGrade())
		throw GradeTooLowException();

	std::cout << "<Drilling noises> BzzzZZzzzBzzz..." << std::endl;

	std::srand(std::time(0));
	int n = std::rand();
	if (n % 2)
		std::cout << this->getName() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy for " << this->getName() << " has failed!" << std::endl;
}
