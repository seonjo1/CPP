#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
	virtual void execute(Bureaucrat cosnt & executor) const;
};

#endif
