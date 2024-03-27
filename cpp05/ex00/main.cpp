#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat A("A", 1);
	Bureaucrat B("B", 150);
	Bureaucrat C("C", 75);
	Bureaucrat D("D", 0);
	Bureaucrat E("E", 151);

	A.incrementGrade();
	B.decrementGrade();
	std::cout << C << std::endl;
	C.incrementGrade();
	std::cout << C << std::endl;
	C.decrementGrade();
	std::cout << C << std::endl;

	return (0);
}