#include <iostream>
#include <cmath>

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

bool bsp(Point const a, Point const b, Point const c, Point const p);

void	tester(Point const a, Point const b, Point const c, Point const p) {
	std::cout << "The point p" << p << " is ";
	if (bsp(a, b, c, p) == 1)
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle a" << a << ", b" << b << ", c" << c << "." << std::string(2, '\n');
}

int main( void ) {

	std::cout << RED"------------------------------------" CLEAR << std::endl;
	std::cout << RED"| Testing Binary Space Partioning  |" CLEAR << std::endl;
	std::cout << RED"------------------------------------" CLEAR << std::string(2, '\n');

	Point a(0.0f, 0.0f);
	Point b(0.0f, 5.0f);
	Point c(5.0f, 2.5f);
	Point p(-1.0f, 2.5f);

	tester(a, b, c, Point(-1.0f, 2.5f));
	tester(a, b, c, Point(1.0f, 2.5f));
	tester(a, b, c, Point(0.0f, 2.5f));
	tester(a, b, c, Point(0.0f, 0.0f));
	tester(a, b, c, Point(2.0f, 1.5f));
}