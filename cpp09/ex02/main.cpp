#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1) throw std::string("too few argument");
		PmergeMe PM(argc, argv);
		PM.sort();
		std::vector<int> res = PM.getResult();
		for (int i = 0; i < static_cast<int>(res.size()); i++)
			std::cout << res[i] << " ";
		std::cout << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	
	return (0);
}