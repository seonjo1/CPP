#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

void printVector(std::vector<int> v)
{
	for (int i = 0; i < static_cast<int>(v.size()); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void printDeque(std::deque<int> d)
{
	for (int i = 0; i < static_cast<int>(d.size()); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1) throw std::string("too few argument");
		PmergeMe PM(argc, argv);

		std::cout << "Beform: ";
		printVector(PM.getResultV());

		struct timespec startV, endV;
		clock_gettime(CLOCK_MONOTONIC, &startV);
		PM.sortV();
		clock_gettime(CLOCK_MONOTONIC, &endV);
		std::cout << "After:  ";
		printVector(PM.getResultV());

		struct timespec startD, endD;
		clock_gettime(CLOCK_MONOTONIC, &startD);
		PM.sortD();
		clock_gettime(CLOCK_MONOTONIC, &endD);
		// std::cout << "AfterD: ";
		// printDeque(PM.getResultD());

		std::cout << "Time to process a range of   " 
			<< PM.getElementSize() 
			<< " elements with std::Vector : " 
			<< (static_cast<double>(endV.tv_nsec) - static_cast<double>(startV.tv_nsec)) / 1000 
			<< " us" << std::endl;

		std::cout << "Time to process a range of   " 
			<< PM.getElementSize() 
			<< " elements with std::Deque : "
			<< (static_cast<double>(endD.tv_nsec) - static_cast<double>(startD.tv_nsec)) / 1000 
			<< " us" << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	
	return (0);
}
