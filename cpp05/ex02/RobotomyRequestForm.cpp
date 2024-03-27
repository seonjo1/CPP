#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(72, 45){};

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target)
	: AForm(name, target, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this!= &obj)
	{
		RobotomyRequestForm::~RobotomyRequestForm();
		new(this) RobotomyRequestForm(obj);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat cosnt & executor) const
{
	if (GradeRequiredToExecute < executor.getGrade()) throw AForm::GradeTooLowException();
	std::cout << "drrrrrrrrr.......\n";
	std::srand(time(0));
	if (rand() & 1)	std::cout << target << "has been robotomized successfully\n";
	else std::cout << target << "robotomization failed\n";
}
