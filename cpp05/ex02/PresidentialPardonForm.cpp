#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target)
	: AForm(name, target, 25, 5) {};

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

void PresidentialPardonForm::execute(Bureaucrat cosnt & executor) const
{
	if (getIsSigned()) throw AForm::FormIsNotSignedException();
	else if (GradeRequiredToExecute < executor.getGrade()) throw AForm::GradeTooLowException();
	std::cout << target << "has been pardoned by Zaphod Beeblebrox\n";
}
