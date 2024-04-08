#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack& copy);
	~MutantStack();
	MutantStack& operator=(const MutantStack& copy);

	typedef typename std::deque<T>::iterator iterator;

	const iterator begin();
	const iterator end();
};

#include "MutantStack.tpp"

#endif
