#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/**
 * TODO: check names 42M/cursus on form and bureacrat ex01
 * TODO: what about "AForm &operator=(const AForm &);" no name after &
 */

#include "AForm.hpp"

class AForm;
class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm &);

		void	execute(Bureaucrat const &officer) const;
};

#endif