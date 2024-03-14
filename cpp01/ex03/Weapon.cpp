#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
	: type(std::string("None")) {};

Weapon::Weapon(std::string type)
	: type(type) {};

const std::string& Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
