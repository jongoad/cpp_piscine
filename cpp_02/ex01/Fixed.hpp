#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	/* Public space */
	public:
		Fixed();										/* Default constructor */
		Fixed(const Fixed &fixed);						/* Copy constructor */
		~Fixed();										/* Destructor */
		Fixed &operator=(const Fixed &fixed);			/* Copy assignment operator */

		Fixed(const int input);							/* Const int constructor */
		Fixed(const float input);						/* Const float constructor */

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;					/* Conver fixed-point value to float */
		int		toInt(void) const;						/* Convert fixed point value to int */

	
	/* Private space */
	private:
		int					fixedValue;
		static const int	fractionalBits = 8;			/* Store the number of fractional bits (counting from the right) */
};

/*--------------------------------------------------*/
/*				Non-member Functions				*/
/*--------------------------------------------------*/
std::ostream &operator<<(std::ostream &ostream,			/* Operator overload for << */
	Fixed const & fixed);
int	getPow(int base, int magnitude);					/* Find the power of a number */

#endif

/*
https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
*/