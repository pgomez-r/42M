#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat b2("tbib", 20);
	try
	{
		Bureaucrat b1("fermli" ,140);
		ShrubberyCreationForm okk("target1");
		okk.beSigned(b1);
		okk.execute(b1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		RobotomyRequestForm kk("target2");
		kk.beSigned(b2);
		kk.execute(b2);
		kk.execute(b2);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b3("malik", 1);
		PresidentialPardonForm ko("target3");
		ko.beSigned(b2);
		b3.exeForm(ko);
		ko.execute(b3);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Bureaucrat op("rajol",2);
		rrf->beSigned(op);
		rrf->execute(op);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
