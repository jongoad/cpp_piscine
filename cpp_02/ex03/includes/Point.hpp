#ifndef POINT_HPP
#define POINT_HPP

#pragma once

#include "Fixed.hpp"

class Point {
	public:
		/* Constructors & Destructors */
		Point();
		Point(float const x, float const y);
		Point(Fixed const x, Fixed const y);
		Point(Point const& other);
		~Point();

		/* Operator Overloads */
		Point operator=(Point const& rhs);
		Point operator-(Point const& rhs);

		/* Setters & Getters */
		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const x;
		Fixed const y;
};

std::ostream& operator<<(std::ostream& o, Point const& rhs);

#endif