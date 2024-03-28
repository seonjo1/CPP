#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& obj)
	: Intern() {static_cast<void>(obj)};

Intern::~Intern() {};

Intern& Intern::operator=(const Intern& obj)
{
	static_cast<void>(obj);
	return (this);
}

AForm* makeForm(std::string form, std::string target)
{
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
		AForm* newForm;

		switch (idx)
		{
			case 0:
				newForm = new ShrubberyCreationForm(target);
				std::cout << "Intern creates " << form << std::endl;
				break ;
			case 1:
				newForm = new RobotomyRequestForm(target);
				std::cout << "Intern creates " << form << std::endl;
				break ;
			case 2:
				newForm = new PresidentialForm(target);
				std::cout << "Intern creates " << form << std::endl;
				break ;
			default:
				throw Intern::NoMatchingFormException();
		}
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
