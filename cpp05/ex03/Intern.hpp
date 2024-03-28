#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	class NoMatchingFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
public:
	Intern();
	Intern(const Intern& obj);
	~Intern();
	Intern&	operator=(const Intern& obj);
	AForm* makeForm(std::string form, std::string target);
	AForm* makeShrubberyCreationForm(std::string target);
	AForm* makeRobotomyRequestForm(std::string target);
	AForm* makePresidentialPardonForm(std::string target);
	AForm* makeException(std::string target);
};

#endif
