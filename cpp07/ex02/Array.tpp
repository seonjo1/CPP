template <typename T>
Array<T>::Array()
{
	arr = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::~Array()
{
	if (arr != NULL)
		delete[] arr;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	arr = new T[copy._size];
	_size = copy._size;

	for (int i = 0; i < _size; i++)
		arr[i] = copy.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (arr != NULL)
			delete[] arr;
		arr = new T[copy._size];
		_size = copy._size;

		for (int i = 0; i < _size; i++)
			arr[i] = copy.arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx >= _size || idx < 0) throw std::exception();
	return (*(arr + idx));
}

template <typename T>
const T& Array<T>::operator[](int idx) const
{
	if (idx >= _size || idx < 0) throw std::exception();
	return (*(arr + idx));
}

template <typename T>
int Array<T>::size() const
{
	return (_size);
}