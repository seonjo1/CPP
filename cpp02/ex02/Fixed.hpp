#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed
{
private:
	int val;
	static const int frac_bit;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();
	int getRawBits() const;
	float toFloat() const;
	int toInt(void) const;
	bool operator>(const Fixed& copy);
	bool operator<(const Fixed& copy);
	bool operator>=(const Fixed& copy);
	bool operator<=(const Fixed& copy);
	bool operator==(const Fixed& copy);
	bool operator!=(const Fixed& copy);
	Fixed operator+(const Fixed& copy);
	Fixed operator-(const Fixed& copy);
	Fixed operator*(const Fixed& copy);
	Fixed operator/(const Fixed& copy);
	Fixed& operator++();
	Fixed& operator--();
	Fixed& operator++(int);
	Fixed& operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif