#include "Point.hpp"

Point::Point() {};

Point::Point(const float x, const float y)
	: x(x), y(y) {};

Point::Point(const Point& obj)
	: x(obj.get_x()), y(obj.get_y()) {};

Point::~Point() {};

Point&	Point::operator=(const Point& obj)
{
	this->~Point();
	new(this) Point(obj);
	return (*this);
}

Fixed Point::get_x() const
{
	return (x);
}

Fixed Point::get_y() const
{
	return (y);
}
