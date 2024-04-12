#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

void printVector(std::vector<int> v)
{
	for (int i = 0; i < static_cast<int>(v.size()); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void printList(std::list<int> l)
{
	std::list<int>::iterator iter = l.begin();
	for (; iter != l.end(); iter++)
		std::cout << *(iter) << " ";
	std::cout << std::endl;
}

int timeCal(struct timeval start, struct timeval end)
{
	int sec = end.tv_sec - start.tv_sec;
	int usec = end.tv_usec - start.tv_usec;

	if (usec < 0)
	{
		sec--;
		usec += 1000000;
	}

	return (sec * 1000000 + usec);
}

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1) throw std::string("too few argument");
		PmergeMe PM(argc, argv);

		std::cout << "Beform: ";
		printVector(PM.getResultV());

		struct timeval startV, endV;
		gettimeofday(&startV, 0);
		PM.sortV();
		gettimeofday(&endV, 0);
		std::cout << "After:  ";
		printVector(PM.getResultV());

		struct timeval startL, endL;
		gettimeofday(&startL, 0);
		PM.sortL();
		gettimeofday(&endL, 0);
		std::cout << "After:  ";
		printList(PM.getResultL());

		std::cout << "Time to process a range of   " 
			<< PM.getElementSize() 
			<< " elements with std::Vector : " 
			<< timeCal(startV, endV) 
			<< " us" << std::endl;

		std::cout << "Time to process a range of   " 
			<< PM.getElementSize() 
			<< " elements with std::List : "
			<< timeCal(startL, endL) 
			<< " us" << std::endl;
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
		return (1);
	}
	
	return (0);
}
