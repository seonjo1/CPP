#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(std::string("PresidentialPardonForm"), target, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		PresidentialPardonForm::~PresidentialPardonForm();
		new(this) PresidentialPardonForm(obj);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned()) throw AForm::FormIsNotSignedException();
	else if (getGradeRequiredToExecute() < executor.getGrade()) throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
