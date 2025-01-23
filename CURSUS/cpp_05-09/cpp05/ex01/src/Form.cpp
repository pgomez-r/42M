
#include "Form.hpp"

Form::Form() : _name("Default Form"), _signGrade(150), _execGrade(150)
{
	this->_isSigned = false;
	std::cout << "Form default constructor called " << std::endl;
}

Form::Form(std::string name, int toSign, int toExecute): _name(name), _signGrade(toSign), _execGrade(toExecute)
{
	if (toSign  > 150 || toExecute > 150)
		throw (GradeTooLowException());
	else if (toSign < 1 || toExecute < 1)
		throw (GradeTooHighException());
	else
	{
		this->_isSigned = false;
		std::cout << name << " Form custom constructor called " << std::endl;
	}
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructor called " << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.checkSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

const std::string Form::getName(void) const
{
	return(this->_name);
}

bool Form::checkSigned() const
{
	return (this->_isSigned);
}

int Form::getSignGrade() const{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(const Bureaucrat &officer)
{
	if (officer.getGrade() <= getSignGrade())
	{
		this->_isSigned = true;
		officer.signForm(*this);
	}
	else
		throw(GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Form Grade too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Form Grade too low");
}

std::ostream &operator<<(std::ostream &output, Form &src)
{
	output << "Form name is: " << src.getName() << std::endl;
	if (src.checkSigned())
		output << "Form is signed" << std::endl;
	else
		output << "Form is not signed" << std::endl;
	output << "Form's grade to sign " << src.getSignGrade()  << std::endl;
	output << "Form's grade to execute " << src.getExecGrade();
	return (output);
}
