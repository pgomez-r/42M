

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "<<..Trying to create bureaucrat with level lower than 150..>>" << std::endl;
	try
	{
		Bureaucrat b1("mskin", 160);
		std::cout << "Bureaucrat created" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "<<..Trying to create bureaucrat with valid level..>>" << std::endl;
	try
	{
		Bureaucrat b2("Paco", 20);
		std::cout << b2 << std::endl;
	} 
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b2("Paco", 20);
	std::cout << "<<..Trying to increase bureaucrat level..>>" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		try
		{
			b2.gradeUp();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b2 << std::endl;
	std::cout << "<<..Trying to decrease bureaucrat level..>>" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		try
		{
			b2.gradeDown();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << b2 << std::endl;
	std::cout << "<<..Trying to exceed bureaucrat level limit..>>" << std::endl;
	for(int i = 0; i < 150; i++)
	{
		try
		{
			b2.gradeUp();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
			break ;
		}
	}
	std::cout << b2 << std::endl;
	return (0);
}
