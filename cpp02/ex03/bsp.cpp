#include "Point.hpp"

float outer_product(Point const p1, Point const p2, Point const p3)
{
	Point vec1((p2.get_x() - p1.get_x()).toFloat(), (p2.get_y() - p1.get_y()).toFloat());
	Point vec2((p3.get_x() - p1.get_x()).toFloat(), (p3.get_y() - p1.get_y()).toFloat());

	float result = ((vec1.get_x() * vec2.get_y()) - (vec2.get_x() * vec1.get_y())).toFloat();
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point arr[3] = {a, b, c};

	if (outer_product(arr[0], arr[1], arr[2]) <= 0)
	{
		arr[1] = c;
		arr[2] = b;
		std::cout << "im here\n";
	}
	for (int i = 0; i < 3; i++)
	{
		if (outer_product(arr[i % 3], arr[(i + 1) % 3], point) <= 0)
			return (false);
	}
	return (true);
}

void print_result(Point const a, Point const b, Point const c, Point const point)
{
	bool result = bsp(a, b, c, point);
	std::cout << "point : (" << point.get_x() << ", " << point.get_y() << ")\n";
	if (result)
		std::cout << "result : true\n\n";
	else
		std::cout << "result : false\n\n";
}