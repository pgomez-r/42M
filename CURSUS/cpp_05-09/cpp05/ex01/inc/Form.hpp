#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureacrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		Form(void);
		Form(const Form &src);
		~Form(void);
		Form(const std::string &name, int signGrade, int execGrade);

		Form 	&operator=(const Form &rhs);	

		const std::string	getName(void) const;
		const int 			getSignGrade(void) const;
		const int 			getExeGrade(void) const;
		bool				getSignedStat(void) const;
		void				beSigned(const Bureacrat &bureacrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				const char  *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char  *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &output, const Form &rhs);

#endif