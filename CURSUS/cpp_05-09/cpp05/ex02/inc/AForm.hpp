#ifndef	AFORM_HPP
#define	AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		AForm();
		AForm(const std::string name, int toSign, int toExecute);
		AForm(AForm &src);
		AForm &operator=(const AForm &);
		virtual ~AForm();

		const std::string	getName() const;
		bool				checkSigned() const;
		virtual void 		execute(Bureaucrat const &officer) const = 0;
		int 				getSignGrade() const;
		int 				getExecGrade() const ;
		void 				beSigned(const Bureaucrat &src);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char  *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char  *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public: 
				const char  *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &op, AForm &src);

#endif
