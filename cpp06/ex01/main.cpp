#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.data = 10;

	std::cout << "Data ptr : " << &data << std::endl;
	std::cout << "Data data : " << data.data << std::endl;
	uintptr_t tmp = Serializer::serialize(&data);
	Data *convertedData = Serializer::deserialize(tmp);
	std::cout << "Converted Data ptr : " << convertedData << std::endl;
	std::cout << "Converted Data data : " << convertedData->data << std::endl;
	return (0);
}