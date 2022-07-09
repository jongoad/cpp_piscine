#include "Fixed.hpp"

/*--------------------------------------------------*/
/*		      Constructors & Destructors	  		*/
/*--------------------------------------------------*/

/* Default constructor */
Fixed::Fixed() {
	this->fixedValue = 0;
	//std::cout << "Default constructor called" << std::endl;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &fixed) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed; 
}

/* Destructor */
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

/* Copy assignment operator */
Fixed &Fixed::operator=(const Fixed &fixed) {
	this->fixedValue = fixed.fixedValue;
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

/* Const int constructor */
Fixed::Fixed(const int input) {
	//std::cout << "Int constructor called" << std::endl;
	//Convert input to fixed point value by bit shifting to the left by fractionalBits
	this->setRawBits(input << this->fractionalBits);
}

/* Const float constructor */
Fixed::Fixed(const float input) {
	//std::cout << "Float constructor called" << std::endl;
	//Convert float to fixed-point value
	//Calc x= floating_inut * 2^fractional_bits
	//Round x to nearest whole number
	//Store x in integer
	this->setRawBits(roundf(input * (1 << this->fractionalBits)));
}

/*--------------------------------------------------*/
/*			 Public Member Functions		  		*/
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


/*--------------------------------------------------*/
/*			Operator Overload Functions		  		*/
/*--------------------------------------------------*/


/*-----------------*/
/* Logic operators */
/*-----------------*/

/* Greater than operator */
bool	Fixed::operator>(const Fixed &fixed) {
	if (fixedValue > fixed.fixedValue)
		return (true);
	else
		return (false);
}	

/* Less than operator */
bool	Fixed::operator<(Fixed const &fixed) {
	if (fixedValue < fixed.fixedValue)
		return (true);
	else
		return (false);
}

/* Greater than or equal to operator */
bool	Fixed::operator>=(Fixed const &fixed) {
	if (fixedValue >= fixed.fixedValue)
		return (true);
	else
		return (false);
}

/* Less than or equal to operator */
bool	Fixed::operator<=(Fixed const &fixed) {
	if (fixedValue <= fixed.fixedValue)
		return (true);
	else
		return (false);
}

/* Equal to operator */
bool	Fixed::operator==(Fixed const &fixed) {
	if (fixedValue == fixed.fixedValue)
		return (true);
	else
		return (false);
}

/* Not equal to operator */
bool	Fixed::operator!=(Fixed const &fixed) {
	if (fixedValue != fixed.fixedValue)
		return (true);
	else
		return (false);
}

/*----------------------*/
/* Arithmetic operators */
/*----------------------*/

/* Addition operator */
float	Fixed::operator+(Fixed const &fixed) {
	return (toFloat() + fixed.toFloat());
}

/* Subtraction operator */
float	Fixed::operator-(Fixed const &fixed) {
	return (toFloat() - fixed.toFloat());
}

/* Multiplication operator */
float	Fixed::operator*(Fixed const &fixed) {
	return (toFloat() * fixed.toFloat());
}
/* Division operator */
float	Fixed::operator/(Fixed const &fixed) {
	return (toFloat() / fixed.toFloat());
}

/*-------------------------------*/
/* Increment/decrement operators */
/*-------------------------------*/

/* Pre-increment operator */
Fixed &Fixed::operator++() {
	fixedValue++;
	return (*this);
}

/* Post-increment operator */
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	fixedValue++;
	return (temp);
}

/* Pre-decrement operator */
Fixed &Fixed::operator--() {
	fixedValue--;
	return (*this);
}

/* Post-decrement operator */
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	fixedValue--;
	return (temp);
}		

/*--------------------------------------------------*/
/*			Overloaded Member Functions				*/
/*--------------------------------------------------*/

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {		/* Return smaller of two fixed points values as reference */
	return (fixed1.fixedValue < fixed2.fixedValue ? fixed1 : fixed2);
}

const Fixed&Fixed::min(const Fixed &fixed1,				/* Return smaller of two const fixed points values as const reference */
	const Fixed &fixed2) {
	return (fixed1.fixedValue < fixed2.fixedValue ? fixed1 : fixed2);	
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {		/* Return larger of two fixed points values as reference */
	return (fixed1.fixedValue > fixed2.fixedValue ? fixed1 : fixed2);
}

const Fixed& Fixed::max(const Fixed &fixed1,			/* Return larger of two const fixed points values as const reference */
	const Fixed &fixed2) {
	return (fixed1.fixedValue > fixed2.fixedValue ? fixed1 : fixed2);
}

/*--------------------------------------------------*/
/*			Private Setter/Getter Functions			*/
/*--------------------------------------------------*/

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

/* Operator overload for stream insertion */
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

/*
Using Q(m.n) format, where m is bits before decimal, and n is bits after
An int is 32 bits wide (4 bytes)
So using fractionalBits = 8, we would have Q(24.8)
1. Convert fixed point value to integer
2. Divide by 2^n (2^8)

VALUE IS NOT STORED AS FIXED POINT BUT AS INT

*/