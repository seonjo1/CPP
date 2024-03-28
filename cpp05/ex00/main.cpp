#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "\n\nINCREMENT GRADE TEST\n\n";
		try
		{
			std::cout << "Make Bureaucrat 'A' grade '0'\n";
			Bureaucrat A("A", 0);
			std::cout << A << std::endl;
			try
			{
				A.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << A << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'B' grade '1'\n";
			Bureaucrat B("B", 1);
			std::cout << B << std::endl;
			try
			{
				B.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'C' grade '75'\n";
			Bureaucrat C("C", 75);
			std::cout << C << std::endl;
			try
			{
				C.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << C << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'D' grade '150'\n";
			Bureaucrat D("D", 150);
			std::cout << D << std::endl;
			try
			{
				D.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << D << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Make Bureaucrat 'E' grade '151'\n";
		try
		{
			Bureaucrat E("E", 151);
			std::cout << E << std::endl;
			try
			{
				E.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << E << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n\nDECREMENT GRADE TEST\n\n";
		try
		{
			std::cout << "Make Bureaucrat 'A' grade '0'\n";
			Bureaucrat A("A", 0);
			std::cout << A << std::endl;
			try
			{
				A.decrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << A << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'B' grade '1'\n";
			Bureaucrat B("B", 1);
			std::cout << B << std::endl;
			try
			{
				B.decrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << B << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'C' grade '75'\n";
			Bureaucrat C("C", 75);
			std::cout << C << std::endl;
			try
			{
				C.decrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << C << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "Make Bureaucrat 'D' grade '150'\n";
			Bureaucrat D("D", 150);
			std::cout << D << std::endl;
			try
			{
				D.decrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << D << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Make Bureaucrat 'E' grade '151'\n";
		try
		{
			Bureaucrat E("E", 151);
			std::cout << E << std::endl;
			try
			{
				E.decrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			std::cout << E << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}