#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
	virtual void execute(Bureaucrat cosnt & executor) const;
};

#endif
