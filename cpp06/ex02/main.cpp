#include <cstdlib>
#include "func.hpp"

// #include <cstdlib>
// void leaks_check()
// {
// 	system("leaks _ex02");
// }

int main()
{
	try
	{
		Base* first = generate();
		Base* second = generate();
		Base* third = generate();

		identify(first);
		identify(second);
		identify(third);

		identify(*first);
		identify(*second);
		identify(*third);

		delete first;
		delete second;
		delete third;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	// atexit(leaks_check);
	return (0);
}