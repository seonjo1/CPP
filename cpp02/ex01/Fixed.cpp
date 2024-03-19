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
	this->val = static_cast<int>(roundf(num * (1 << frac_bit)));
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

void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

float Fixed::toFloat() const
{
	return ((static_cast<float>(this->val)) / (1 << frac_bit));
}

int Fixed::toInt(void) const
{
	return (this->val >> frac_bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
