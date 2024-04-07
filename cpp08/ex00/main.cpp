#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(5, 0);

	for (int i = 0; i < 5; i++)
		v[i] = i;

	std::cout << easyfind(v, -2) << std::endl;
	std::cout << easyfind(v, 0) << std::endl;
	std::cout << easyfind(v, 3) << std::endl;
	std::cout << easyfind(v, 6) << std::endl;
}