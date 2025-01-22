
#include "AForm.hpp"

AForm::AForm() : _name("Default Form"), _signGrade(150), _execGrade(150)
{
	this->_isSigned = false;
	std::cout << "AForm default constructor called " << std::endl;
}

AForm::AForm(std::string name, int toSign, int toExecute): _name(name), _signGrade(toSign), _execGrade(toExecute)
{
	if (toSign  > 150 || toExecute > 150)
		throw (GradeTooLowException());
	else if (toSign < 1 || toExecute < 1)
		throw (GradeTooHighException());
	else
	{
		this->_isSigned = false;
		std::cout << name << " AForm custom constructor called " << std::endl;
	}
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destructor called " << std::endl;
}

AForm::AForm(AForm &src) : _name(src.getName()), _isSigned(src.checkSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::checkSigned() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= getSignGrade())
	{
		this->_isSigned = true;
		src.signAForm(*this);
	}
	else
		throw(GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Form Grade too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Form Grade too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Error: Form is NOT signed or Grade is too low/high to execute");
}

/**
 * TODO: check ternary "? :" and understand properly or replace
 */
std::ostream &operator<<(std::ostream &op, AForm& src)
{
	op << "AForm name is: " << src.getName() << std::endl;
	op << (src.checkSigned() ?  "AForm is signed" : "AForm is not signed") << std::endl;
	op << "AForm's grade to sign " << src.getSignGrade()  << std::endl;
	op << "AForm's grade to execute " << src.getExecGrade();
	return (op);
}
