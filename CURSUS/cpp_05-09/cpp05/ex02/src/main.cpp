#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		std::cout << "Creating a valid bureaucrat..." << std::endl;
		Bureaucrat	b1("Rick", 40);
		std::cout << b1 << std::endl;
		std::cout << "///---SHRUBBERY FORM TEST---\\\\\\" << std::endl;
		try
		{
			std::cout << "Creating second valid bureaucrat..." << std::endl;
			Bureaucrat	b2("Morty", 130);
			std::cout << b2 << std::endl;
			ShrubberyCreationForm	shrub("Shrubb Form");
			std::cout << shrub << std::endl;
			std::cout << "Trying to sign " << shrub.getName() << " by officer: " << b2.getName() << std::endl;
			b2.signForm(shrub);
			std::cout << "Trying to execute " << shrub.getName() << " by officer: " << b2.getName() << std::endl;
			shrub.execute(b2);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "///---ROBOTOMY FORM TEST---\\\\\\" << std::endl;
		try
		{
			RobotomyRequestForm	roboto("Robotomy Form");
			std::cout << "Trying to sign " << roboto.getName() << " by officer: " << b1.getName() << std::endl;
			b1.signForm(roboto);
			std::cout << "Trying to execute " << roboto.getName() << " by officer: " << b1.getName() << std::endl;
			roboto.execute(b1);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "///---PRESIDENTIAL FORM TEST---\\\\\\" << std::endl;
		try
		{
			std::cout << "Creating a valid bureaucrat..." << std::endl;
			Bureaucrat	b3("Randy", 10);
			std::cout << b3 << std::endl;
			PresidentialPardonForm presi("Presidential Form");
			std::cout << "Trying to sign " << presi.getName() << " by officer: " << b3.getName() << std::endl;
			b3.signForm(presi);
			std::cout << "Trying to execute " << presi.getName() << " by officer: " << b3.getName() << std::endl;
			presi.execute(b3);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch(std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}
	return (0);
}
