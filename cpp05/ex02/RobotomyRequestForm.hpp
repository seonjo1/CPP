#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name, std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
	virtual void execute(Bureaucrat cosnt & executor) const;
};

#endif
