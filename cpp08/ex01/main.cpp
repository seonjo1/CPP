#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(100000);
	sp.addNumbers(1, 50000);
	sp.addNumbers(1000, 49998);
	sp.addNumber(100000);

	try
	{
		sp.addNumbers(100, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumbers(100, 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumber(10);
		std::cout << "last element input\n";
		sp.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
