#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	virtual ~RobotomyRequestForm();
	virtual RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
