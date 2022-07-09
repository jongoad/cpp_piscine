#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed() {
	this->fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed; 
}

/* Destructor */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Copy assignment operator */
Fixed &Fixed::operator=(const Fixed &fixed) {
	this->fixedValue = fixed.fixedValue;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

/* Const int constructor */
Fixed::Fixed(const int input) {
	std::cout << "Int constructor called" << std::endl;
	//Convert input to fixed point value by bit shifting to the left by fractionalBits
	this->setRawBits(input << this->fractionalBits);
}

/* Const float constructor */
Fixed::Fixed(const float input) {
	std::cout << "Float constructor called" << std::endl;
	//Convert float to fixed-point value
	//Calc x= floating_inut * 2^fractional_bits
	//Round x to nearest whole number
	//Store x in integer
	this->setRawBits(roundf(input * (1 << this->fractionalBits)));
}


/*--------------------------------------------------*/
/*			Private Setter/Getter Functions			*/
/*--------------------------------------------------*/

/* Convert fixed points to int and return */
int	Fixed::toInt(void) const {
	return(this->getRawBits() >> this->fractionalBits);
}

/* Convert fixed point to floating point and return */
float	Fixed::toFloat(void) const {
	float result = (float)this->fixedValue / getPow(2, this->fractionalBits);
	return (result);
}

/*
Using Q(m.n) format, where m is bits before decimal, and n is bits after
An int is 32 bits wide (4 bytes)
So using fractionalBits = 8, we would have Q(24.8)
1. Convert fixed point value to integer
2. Divide by 2^n (2^8)

VALUE IS NOT STORED AS FIXED POINT BUT AS INT

*/

/* Retrieve bit value from private */
int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

/* Set bit value in private */
void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}

/*--------------------------------------------------*/
/*				Non-member Functions				*/
/*--------------------------------------------------*/

// /* Operator overload for stream insertion */
std::ostream &operator<<(std::ostream &ostream, Fixed const & output) {

	ostream << output.toFloat();
	return (ostream);
}

/* Get the result of a power */
int	getPow(int base, int magnitude) {
	int	result = base;
	for (int i = magnitude; i > 1; i--)
		result = result * base;
	return (result);
}

/*
https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e
*/

