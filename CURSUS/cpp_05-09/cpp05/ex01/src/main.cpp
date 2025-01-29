
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat	b1("Paco", 100);
		std::cout << "Bureaucrat B1 created successfully" << std::endl;
		std::cout << b1 << std::endl;

		try
		{
			std::cout << "Trying to create Bureaucrat with a grade value out of range..." << std::endl;
			Bureaucrat	b2("Paquito",200); // Throws std::exception (invalid grade)
			std::cout << "This line should not be printed." << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		Form	document("Form 42", 10, 130);
		std::cout << "Form document created successfully." << std::endl;
		std::cout << document << std::endl;

		try
		{
			std::cout << "Trying to create Form with a grade value out of range..." << std::endl;	
			Form	invalidForm("Non-valid form", 100, -20); // Throws std::exception (invalid parameters)
			std::cout << "This line should not be printed." << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "Creating a valid bureaucrat..." << std::endl;
		Bureaucrat	b2("Fernanda", 5);
		std::cout << b2 << std::endl;
		try
		{
			b2.signForm(document);
			std::cout << "Form signed successfully" << std::endl;
			std::cout << document << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "Creating bureaucrat with not enough grade to sign form..." << std::endl;
			Bureaucrat b3("Bernie", 150); 
			std::cout << b3 << std::endl;
			document.beSigned(b3); // Throws std::exception (insufficient grade)
			std::cout << "This line should not be printed" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}
	return (0);
}
