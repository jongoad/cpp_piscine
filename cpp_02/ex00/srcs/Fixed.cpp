#include "../includes/Fixed.hpp"

/* Constructors & Destructor */
Fixed::Fixed() : fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Operator Overloads */
Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = rhs.getRawBits();
	return (*this);
}

/* Setters & Getters */
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}