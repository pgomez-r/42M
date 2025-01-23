#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		Form(void);
		Form(const Form &src);
		~Form(void);
		Form(const std::string name, int toSign, int toExecute);

		Form 	&operator=(const Form &src);	

		const std::string	getName(void) const;
		int 				getSignGrade(void) const;
		int 				getExecGrade(void) const;
		bool				checkSigned(void) const;
		void				beSigned(const Bureaucrat &officer);

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

std::ostream	&operator<<(std::ostream &output, const Form &src);

#endif
