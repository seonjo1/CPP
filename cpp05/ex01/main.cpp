#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat A("A", 1);
	Bureaucrat B("B", 150);
	Bureaucrat C("C", 50);
	Form F("F", 50, 50);
	Form G("G", 40, 40);
	B.signForm(F);
	C.signForm(F);
	A.signForm(F);
	std::cout << F << std::endl;
	std::cout << G << std::endl;
}