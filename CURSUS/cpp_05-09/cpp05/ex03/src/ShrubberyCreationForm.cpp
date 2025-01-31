
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", 145 , 137)
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "Shrubbery custom constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery " << getName() << " destructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	std::cout << "Shrubbery copy consturctor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	(void)src;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &officer ) const
{
	if (!this->checkSigned())
		throw FormNotSigned();
	else if (officer.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else
	{
		std::string fileName = this->getName() + "_shrubbery";
		std::ofstream out(fileName.c_str());
		if (!out.is_open() || out.fail())
		{
			std::cerr << "Error: Could not open/create file " << fileName << std::endl;
			return ;
		}
		else
		{
			std::ofstream out;
			out.open(fileName.c_str());
			out << "        _-_\n";
			out << "     /~~   ~~\\\n";
			out << "  /~~         ~~\\\n";
			out << " {               }\n";
			out << "  \\  _-     -_  /\n";
			out << "    ~  \\ //  ~\n";
			out << " _- -   | | _- _\n";
			out << "   _ -  | |   -_\n";
			out << "       // \\\\\n";
			out << "      //   \\\\\n";
			out << "     //     \\\\\n";
			out << "    //       \\\\\n";
			out << "   //         \\\\\n";
			out << "  //           \\\\\n";
			out << " //             \\\\\n";
			out << "//               \\\\\n";
			out << "===================\n";
			out << "      ||||| |||||\n";
			out << "      ||||| |||||\n";
			out << "      ||||| |||||\n";
			out << "      ||||| |||||\n";
			out << "      ||||| |||||\n";;
			out.close();
			if (out.fail())
				std::cerr << "Error: Could not write to file " << fileName << std::endl;
		}
	}
}
