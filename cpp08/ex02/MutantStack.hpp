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

	iterator begin();
	iterator end();
	const iterator begin() const;
	const iterator end() const;
};

#include "MutantStack.tpp"

#endif
