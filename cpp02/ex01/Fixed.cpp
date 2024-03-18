#include "Fixed.hpp"
#include <cmath>
const int Fixed::frac_bit = 8;

Fixed::Fixed()
	: val(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	this->val = (num << frac_bit);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->val = static_cast<int>(roundf(num * std::pow(2, frac_bit)));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	this->val = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called\n";
	this->val = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	return (this->val);
}

float Fixed::toFloat() const
{
	return ((static_cast<float>(this->val)) / 256);
}

int Fixed::toInt(void) const
{
	return (this->val >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
