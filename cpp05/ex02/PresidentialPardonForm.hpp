#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	virtual ~PresidentialPardonForm();
	virtual PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
