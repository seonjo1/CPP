#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		idea[i] = copy.idea[i];
	std::cout << "Brain constructor called\n";
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			idea[i] = copy.idea[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}
