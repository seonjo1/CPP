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
	void setRawBits(int const raw);
	
	float toFloat() const;
	int toInt(void) const;

	bool operator>(const Fixed& obj);
	bool operator<(const Fixed& obj);
	bool operator>=(const Fixed& obj);
	bool operator<=(const Fixed& obj);
	bool operator==(const Fixed& obj);
	bool operator!=(const Fixed& obj);
	
	Fixed operator+(const Fixed& obj);
	Fixed operator-(const Fixed& obj);
	Fixed operator*(const Fixed& obj);
	Fixed operator/(const Fixed& obj);
	
	Fixed& operator++();
	Fixed& operator--();
	const Fixed operator++(int);
	const Fixed operator--(int);
	
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	const static Fixed& min(const Fixed& a, const Fixed& b);
	const static Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif