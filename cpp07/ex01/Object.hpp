#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <iostream>
# include <string>

class Object
{
private:
	std::string name;
	int num;
public:
	Object(std::string name, int num);
	~Object();
	Object(const Object& copy);
	Object& operator=(const Object& copy);
	std::string getName() const;
	int getNum() const;
	Object operator-(const int num);
};

# include "Object.tpp"

#endif