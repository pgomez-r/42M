

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat")
{
	this->_grade = 150;
	std::cout << "Bureaucrat default constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	this->_grade = src._grade;
	std::cout << "Bureaucrat copy constructor called " << std::endl;
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
	std::cout << "Bureaucrat custom constructor called " << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor called " << std::endl;
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp(void)
{
	if (this->_grade - 1 < 1)
		throw	Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::gradeDown(void)
{
	if (this->_grade + 1 > 150)
		throw	Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &rhs)
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (output);
}

const char	*Bureaucrat::GradeTooHighException::what()const throw()
{
	return ("Error: Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what()const throw()
{
	return ("Error: Grade too low");
}
