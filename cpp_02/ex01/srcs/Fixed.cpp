#include "../includes/Fixed.hpp"

/*--------------------------------------------------*/
/*		      Constructors & Destructors	  		*/
/*--------------------------------------------------*/

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0; }
Fixed::Fixed(int const input) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(input << this->fractionalBits); }
Fixed::Fixed(float const input) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(input * (1 << this->fractionalBits))); }
Fixed::Fixed(Fixed const& other) { 
	std::cout << "Copy constructor called" << std::endl;
	*this = other; }
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*--------------------------------------------------*/
/*			Operator Overload Functions		  		*/
/*--------------------------------------------------*/

Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = rhs.getRawBits();
	return (*this);
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