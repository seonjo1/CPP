#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat A("A", 1);
	Bureaucrat B("B", 150);
	Bureaucrat C("C", 50);
	Form F("F", 50, 50);
	B.signForm(F);
	C.signForm(F);
	A.signForm(F);
}