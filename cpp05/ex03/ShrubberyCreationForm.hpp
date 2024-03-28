#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	virtual ~ShrubberyCreationForm();
	virtual ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
