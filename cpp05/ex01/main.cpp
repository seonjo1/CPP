#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "CONSTRUCTOR EXCEPTION TEST\n\n";
		std::cout << "Create Form 'a' grade '0, 1'\n";
		try
		{
			Form a("a", 0, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Create Form 'b' grade '1, 0'\n";
		try
		{
			Form b("b", 1, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Create Form 'c' grade '151, 150'\n";
		try
		{
			Form c("c", 151, 150);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Create Form 'd' grade '150, 151'\n";
		try
		{
			Form d("d", 150, 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	try
	{
		Bureaucrat A("A", 1);
		Bureaucrat B("B", 50);
		Bureaucrat C("C", 150);
	
		{
			std::cout << "\n\nBureaucrat 'A' SIGN TEST\n\n";
			std::cout << A << std::endl;

			std::cout << "\n----SIGN TEST Form 'a'----\n\n";
			Form a("a", 10, 10);
			std::cout << a << std::endl;
			A.signForm(a);
			std::cout << a << std::endl;

			std::cout << "\n----SIGN TEST Form 'b'----\n\n";
			Form b("b", 70, 70);
			std::cout << b << std::endl;
			A.signForm(b);
			std::cout << b << std::endl;

			std::cout << "\n----SIGN TEST Form 'c'----\n\n";
			Form c("c", 150, 150);
			std::cout << c << std::endl;
			A.signForm(c);
			std::cout << c << std::endl;
		}

		{
			std::cout << "\n\nBureaucrat 'B' SIGN TEST\n\n";
			std::cout << B << std::endl;

			std::cout << "\n----SIGN TEST Form 'a'----\n\n";
			Form a("a", 10, 10);
			std::cout << a << std::endl;
			B.signForm(a);
			std::cout << a << std::endl;

			std::cout << "\n----SIGN TEST Form 'b'----\n\n";
			Form b("b", 70, 70);
			std::cout << b << std::endl;
			B.signForm(b);
			std::cout << b << std::endl;

			std::cout << "\n----SIGN TEST Form 'c'----\n\n";
			Form c("c", 150, 150);
			std::cout << c << std::endl;
			B.signForm(c);
			std::cout << c << std::endl;
		}

		{
			std::cout << "\n\nBureaucrat 'C' SIGN TEST\n\n";
			std::cout << C << std::endl;

			std::cout << "\n----SIGN TEST Form 'a'----\n\n";
			Form a("a", 10, 10);
			std::cout << a << std::endl;
			C.signForm(a);
			std::cout << a << std::endl;

			std::cout << "\n----SIGN TEST Form 'b'----\n\n";
			Form b("b", 70, 70);
			std::cout << b << std::endl;
			C.signForm(b);
			std::cout << b << std::endl;

			std::cout << "\n----SIGN TEST Form 'c'----\n\n";
			Form c("c", 150, 150);
			std::cout << c << std::endl;
			C.signForm(c);
			std::cout << c << std::endl;
		}
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}