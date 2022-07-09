#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed() {
	this->fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &fixed) {
	this->setRawBits(fixed.fixedValue);
	std::cout << "Copy constructor called" << std::endl;
}

/* Destructor */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Copy assignment operator */
Fixed& Fixed::operator=(const Fixed &fixed) {
	this->fixedValue = fixed.getRawBits();
	return *this;
	std::cout << "Copy assignment operator called" << std::endl;

}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}