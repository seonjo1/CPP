#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>

struct Data
{
	int data;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& obj);
	Serializer&	operator=(const Serializer& obj);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
