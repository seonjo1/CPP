#include "Fixed.hpp"
#include <cmath>
const int Fixed::frac_bit = 8;

Fixed::Fixed()
	: val(0) {};

Fixed::Fixed(const int num)
{
	this->val = (num << frac_bit);
}

Fixed::Fixed(const float num)
{
	this->val = static_cast<int>(roundf(num * (1 << frac_bit)));
}

Fixed::Fixed(const Fixed& copy)
{
	this->val = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	this->val = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed() {};

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

bool Fixed::operator>(const Fixed& obj)
{
	if (this->getRawBits() > obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& obj)
{
	if (this->getRawBits() < obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& obj)
{
	if (this->getRawBits() >= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& obj)
{
	if (this->getRawBits() <= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& obj)
{
	if (this->getRawBits() == obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& obj)
{
	if (this->getRawBits() != obj.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& obj)
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() + obj.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed& obj)
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() - obj.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed& obj)
{
	Fixed ret(this->toFloat() * obj.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed& obj)
{
	Fixed ret(this->toFloat() / obj.toFloat());
	return (ret);
}

Fixed& Fixed::operator++()
{
	this->val++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->val--;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	this->val++;
	return(ret);
}

const Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->val--;
	return(ret);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}
