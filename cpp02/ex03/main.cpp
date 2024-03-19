#include "Point.hpp"

void print_result(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point const a(0.0f, 0.0f);
	Point const b(1.0f, 0.0f);
	Point const c(0.0f, 1.0f);

	Point const point1(0.25f, 0.25f);
	print_result(a, b, c, point1);
	
	Point const point2(0.7f, 0.2f);
	print_result(a, b, c, point2);

	Point const point3(0.0f, 0.0f);
	print_result(a, b, c, point3);

	Point const point4(1.0f, 0.0f);
	print_result(a, b, c, point4);

	Point const point5(0.5f, 0.5f);
	print_result(a, b, c, point5);

	Point const point6(0.49f, 0.5f);
	print_result(a, b, c, point6);

	Point const point7(0.6f, 0.5f);
	print_result(a, b, c, point7);

	Point const point8(-0.1f, 0.5f);
	print_result(a, b, c, point8);

	return 0;
}