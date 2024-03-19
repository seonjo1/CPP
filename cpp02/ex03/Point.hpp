#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& obj);
	~Point();
	Point&	operator=(const Point& obj);
	Fixed get_x() const;
	Fixed get_y() const;
};

#endif
