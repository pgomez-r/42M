

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		this->_grade = 150;
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		this->_grade = 150;
	}
}

Bureaucrat::~Bureaucrat(void){
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp(void)
{
	if (this->_grade - 1 < 1)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::gradeDown(void)
{
	if (this->_grade + 1 > 150)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &rhs)
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}
