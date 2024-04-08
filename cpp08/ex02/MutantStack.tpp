template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy)
	: std::stack<T>(copy) {};

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& copy)
{
	if (this != &copy)
		std::stack<T>::operator=(copy);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
const typename MutantStack<T>::iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
const typename MutantStack<T>::iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}