#include "Fixed.hpp"

int frac_bit = 8;

Fixed::Fixed()
	: val(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	this->val = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->val = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->val);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}
