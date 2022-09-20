#include "../includes/Fixed.hpp"

/*--------------------------------------------------*/
/*		      Constructors & Destructors	  		*/
/*--------------------------------------------------*/

Fixed::Fixed() { this->fixedValue = 0; }
Fixed::Fixed(int const input) { this->setRawBits(input << this->fractionalBits); }
Fixed::Fixed(float const input) { this->setRawBits(roundf(input * (1 << this->fractionalBits))); }
Fixed::Fixed(Fixed const& other) { *this = other; }
Fixed::~Fixed() { }

/*--------------------------------------------------*/
/*			Operator Overload Functions		  		*/
/*--------------------------------------------------*/

Fixed&	Fixed::operator=(Fixed const& rhs) {
	this->fixedValue = rhs.getRawBits();
	return (*this);
}

/*-----------------*/
/* Logic operators */
/*-----------------*/

bool	Fixed::operator>(const Fixed& rhs) const{ return (fixedValue > rhs.fixedValue); }	
bool	Fixed::operator<(Fixed const& rhs) const{ return (fixedValue < rhs.fixedValue); }
bool	Fixed::operator>=(Fixed const& rhs) const{ return (fixedValue >= rhs.fixedValue); }
bool	Fixed::operator<=(Fixed const& rhs) const{ return (fixedValue <= rhs.fixedValue); }
bool	Fixed::operator==(Fixed const& rhs) const{ return (fixedValue == rhs.fixedValue); }
bool	Fixed::operator!=(Fixed const& rhs) const{ return (fixedValue != rhs.fixedValue); }

/*----------------------*/
/* Arithmetic operators */
/*----------------------*/

/* Addition operator */
Fixed	Fixed::operator+(Fixed const& rhs) const{
	Fixed res;
	res.setRawBits(this->fixedValue + rhs.getRawBits());
	return (res);
}

/* Subtraction operator */
Fixed	Fixed::operator-(Fixed const& rhs) const{
	Fixed res;
	res.setRawBits(this->fixedValue - rhs.getRawBits());
	return (res);
}

/* Multiplication operator */
Fixed	Fixed::operator*(Fixed const& rhs) const{
	Fixed res;
	res.setRawBits((this->fixedValue * rhs.getRawBits()) >> fractionalBits);
	return (res);
}
/* Division operator */
Fixed	Fixed::operator/(Fixed const& rhs) const{
	Fixed res;
	res.setRawBits((this->fixedValue << fractionalBits) /rhs.getRawBits());
	return (res);;
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

/*------------------------------------------*/
/*		    	Setters & Getters	    	*/
/*------------------------------------------*/

int		Fixed::getRawBits(void) const { return (this->fixedValue); }
void	Fixed::setRawBits(int const raw) { this->fixedValue = raw; }

/*--------------------------------------------------*/
/*				Public Member Functions				*/
/*--------------------------------------------------*/
int	Fixed::toInt(void) const {
	return(this->getRawBits() >> this->fractionalBits);
}

float	Fixed::toFloat(void) const {
	float result = static_cast<float>(this->fixedValue) / getPow(2, this->fractionalBits);
	return (result);
}

/*--------------------------------------------------*/
/*			Overloaded Member Functions				*/
/*--------------------------------------------------*/

Fixed&			Fixed::min(Fixed &fixed1, Fixed& fixed2) {
	return (fixed1.fixedValue < fixed2.fixedValue ? fixed1 : fixed2);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	return (fixed1.fixedValue < fixed2.fixedValue ? fixed1 : fixed2);	
}

Fixed&			Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1.fixedValue > fixed2.fixedValue ? fixed1 : fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	return (fixed1.fixedValue > fixed2.fixedValue ? fixed1 : fixed2);
}

/*--------------------------------------------------*/
/*				Non-member Functions				*/
/*--------------------------------------------------*/

/* Operator overload for stream insertion */
std::ostream&	operator<<(std::ostream& ostream, Fixed const& output) {
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