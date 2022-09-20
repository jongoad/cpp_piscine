#include "../includes/Point.hpp"

/* Constructors & Destructor */

Point::Point() {}
Point::Point(float const x, float const y) : x(x), y(y) {}
Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {}
Point::Point(Point const& other) : x(other.x), y(other.y) { }
Point::~Point() {}

/* Operator Overloads */
Point Point::operator=(Point const& rhs) {
	return (Point(rhs.getX(), rhs.getY()));
}

Point Point::operator-(Point const& rhs) {
	return (Point(x - rhs.getX(), y - rhs.getY()));
}

/* Setters & Getters */
Fixed	Point::getX(void) const{
	return (this->x);
}

Fixed	Point::getY(void) const{
	return (this->y);
}

/* External Operator Overload */
std::ostream& operator<<(std::ostream& o, Point const& rhs) {
	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (o);
}