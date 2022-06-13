#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed() {
	this->fixedValue = 0;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &fixed) {

}

/* Destructor */
Fixed::~Fixed() {

}	

int		Fixed::getRawBits(void) const {
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw) {

}