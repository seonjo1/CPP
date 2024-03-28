#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(std::string("robotomy request"), target, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this!= &obj)
	{
		this->~RobotomyRequestForm();
		new(this) RobotomyRequestForm(obj);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static bool first = true;

	if (!getIsSigned()) throw AForm::FormIsNotSignedException();
	else if (getGradeRequiredToExecute() < executor.getGrade()) throw AForm::GradeTooLowException();
	std::cout << "drrrrrrrrr.......\n";
	if (first)
	{
		first = false;
		std::srand(time(0));
	}
	if (rand() & 1)	std::cout << getTarget() << " has been robotomized successfully\n";
	else std::cout << getTarget() << " robotomization failed\n";
}
