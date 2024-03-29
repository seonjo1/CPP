#include "func.hpp"

Base * generate(void)
{
	static bool first = true;
	
	if (first)
	{
		first = false;
		srand(time(0));
	}
	
	int num = rand();

	switch (num % 3)
	{
		case 0:
			return (new A());
		case 1: 
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "this pointer is A\n";
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "this pointer is B\n";
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "this pointer is C\n";
		return ;
	}
	else
	{
		std::cout << "this pointer is not A, B, or C\n";
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		A Atest = dynamic_cast<A&>(p);
		std::cout << "this reference is A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			B Btest = dynamic_cast<B&>(p);
			std::cout << "this reference is B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C Ctest = dynamic_cast<C&>(p);
				std::cout << "this reference is C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "this reference is not A, B, or C\n";
			}
		}
	}
}