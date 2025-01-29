#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/**
 * TODO: ex02 - ex03: check mains with
 */

int main()
{
	try
	{
		std::cout << "Creating new intern... Welcome to the company!" << std::endl;
		Intern		morty;
		std::cout << "Creating new bureaucrat..." << std::endl;
		Bureaucrat	b1("Rick",2);
		std::cout << b1 << std::endl;
		std::cout << "Creating an auxiliar pointer to AForm..." << std::endl;
		AForm		*form_ptr;
	
		std::string	form_type = "presidential pardon";
		std::string	form_name = "Bender";
		std::cout << "Intern will try create a form of type " << form_type << " and that will be called " << form_name << std::endl;
		form_ptr = morty.makeForm("presidential pardon", "Bender");
		b1.signForm(*form_ptr);
		form_ptr->beSigned(b1);
		form_ptr->execute(b1);
		delete(form_ptr);
	}
	catch (std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}
	return (0);
}
