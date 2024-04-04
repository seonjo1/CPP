#include "Object.hpp"

Object::Object(std::string name, int num)
	: name(name), num(num) {};

Object::~Object() {};

Object::Object(const Object& copy)
	: name(copy.name), num(copy.num) {};

Object& Object::operator=(const Object& copy)
{
	if (this != &copy)
	{
		name = copy.name;
		num = copy.num;
	}
	return (*this);
}

std::string Object::getName() const {	return (name); }

int Object::getNum() const { return (num); }

bool Object::operator<(Object& obj) { return (this->num < obj.num);	}
bool Object::operator>(Object& obj) { return (this->num > obj.num);	}
bool Object::operator<(const Object& obj) const { return (this->num < obj.num);	}
bool Object::operator>(const Object& obj) const { return (this->num > obj.num);	}
