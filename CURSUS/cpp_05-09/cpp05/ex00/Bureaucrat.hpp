

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class   Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);

		Bureaucrat  &operator=(const Bureaucrat &rhs);

		std::string getName(void);
		std::string getGrade(void);
		void        gradeUp(void);    
		void        gradeDown(void);

		class   GradeTooHighException : public std::exception
		{
			public:
				virtual const char  *what() const throw(){
					return ("Error: Grade too high");
				}
		};
		class   GradeTooLowException : public std::exception
		{
			public:
				virtual const char  *what() const throw(){
					return ("Error: Grade too low");
				}
		};
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat);

#endif