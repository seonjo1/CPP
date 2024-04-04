template<typename U>
void printValue(U& value)
{
	value = value - 1;
	std::cout << value << std::endl;
}

template<typename U>
void printValue(const U& value)
{
	std::cout << value << std::endl;
}
