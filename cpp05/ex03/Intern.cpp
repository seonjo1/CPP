#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& obj)
{
	static_cast<void>(obj);
}

Intern::~Intern() {};

Intern& Intern::operator=(const Intern& obj)
{
	static_cast<void>(obj);
	return (*this);
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeException(std::string target)
{
	static_cast<void>(target);
	throw Intern::NoMatchingFormException();
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	static AForm* (Intern::*functions[4])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, 
		&Intern::makePresidentialPardonForm, &Intern::makeException};
	static std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int idx = 3;
	for (int i = 0; i < 3; i++)
	{
		if (form == arr[i])
		{
			idx = i;
			break ;
		}
	}

	try
	{
		AForm* newForm = (this->*functions[idx])(target);
		std::cout << "Intern creates " << form << std::endl;
		return (newForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

const char* Intern::NoMatchingFormException::what() const throw()
{
	return ("there is no matching form format");
}
