

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class   Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);

		Bureaucrat 	&operator=(const Bureaucrat &rhs);

		const std::string	getName(void) const;
		int 				getGrade(void) const;
		void				gradeUp(void);    
		void				gradeDown(void);

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

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &rhs);

#endif