#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <exception>

template <typename T>
class Array
{
private:
	T *arr;
	int _size;

public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	T& operator[](int idx);
	const T& operator[](int idx) const;
	int size() const;
};

# include "Array.tpp"

#endif