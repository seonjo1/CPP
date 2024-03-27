#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Bureaucrat A("A", 150);
		
		ShrubberyCreationForm shrubberyForm("shrubberyForm", "seonjo");
		RobotomyRequestForm roboForm1("roboForm1", "seonjo");
		RobotomyRequestForm roboForm2("roboForm2", "seonjo");
		RobotomyRequestForm roboForm3("roboForm3", "seonjo");
		PresidentialPardonForm PardonForm("PardonForm", "seonjo");

		A.signForm(shrubberyForm);
		A.signForm(roboForm1);
		A.signForm(roboForm2);
		A.signForm(roboForm3);
		A.signForm(PardonForm);

		A.executeForm(shrubberyForm);
		A.executeForm(roboForm1);
		A.executeForm(roboForm2);
		A.executeForm(roboForm3);
		A.executeForm(PardonForm);
	}

	{
		Bureaucrat B("B", 50);

		ShrubberyCreationForm shrubberyForm("shrubberyForm", "seonjo");
		RobotomyRequestForm roboForm1("roboForm1", "seonjo");
		RobotomyRequestForm roboForm2("roboForm2", "seonjo");
		RobotomyRequestForm roboForm3("roboForm3", "seonjo");
		PresidentialPardonForm PardonForm("PardonForm", "seonjo");

		B.signForm(shrubberyForm);
		B.signForm(roboForm1);
		B.signForm(roboForm2);
		B.signForm(roboForm3);
		B.signForm(PardonForm);

		B.executeForm(shrubberyForm);
		B.executeForm(roboForm1);
		B.executeForm(roboForm2);
		B.executeForm(roboForm3);
		B.executeForm(PardonForm);
	}
	{
		Bureaucrat C("C", 50);

		ShrubberyCreationForm shrubberyForm("shrubberyForm", "seonjo");
		RobotomyRequestForm roboForm1("roboForm1", "seonjo");
		RobotomyRequestForm roboForm2("roboForm2", "seonjo");
		RobotomyRequestForm roboForm3("roboForm3", "seonjo");
		PresidentialPardonForm PardonForm("PardonForm", "seonjo");

		C.signForm(shrubberyForm);
		C.signForm(roboForm1);
		C.signForm(roboForm2);
		C.signForm(roboForm3);
		C.signForm(PardonForm);

		C.executeForm(shrubberyForm);
		C.executeForm(roboForm1);
		C.executeForm(roboForm2);
		C.executeForm(roboForm3);
		C.executeForm(PardonForm);
	}
	return (0);
}