#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm>

template <typename T>
int easyfind(const T& container, int num)
{
	int idx = std::find(container.begin(), container.end(), num) - container.begin();
	if (idx == static_cast<int>(container.size()))
		idx = -1;
	return (idx);
}

#endif
