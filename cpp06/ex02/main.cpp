#include <cstdlib>
#include "func.hpp"

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
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	return (0);
}