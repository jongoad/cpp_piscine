#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();												/* Default constructor */
		Fixed(const Fixed &fixed);								/* Copy constructor */
		~Fixed();												/* Destructor */
		Fixed &operator=(const Fixed &fixed);					/* Copy assignment operator */

		Fixed(const int input);									/* Const int constructor */
		Fixed(const float input);								/* Const float constructor */

		/*--------------------------------------------------*/
		/*			Operator Overload Functions				*/
		/*--------------------------------------------------*/

		/* Logic operators */

		bool	operator>(const Fixed &fixed);					/* Greater than operator */
		bool	operator<(const Fixed &fixed);					/* Less than operator */
		bool	operator>=(const Fixed &fixed);					/* Greater than or equal to operator */
		bool	operator<=(const Fixed &fixed);					/* Less than or equal to operator */
		bool	operator==(const Fixed &fixed);					/* Equal to operator */
		bool	operator!=(const Fixed &fixed);					/* Not equal to operator */
	
		/* Arithmetic operators */
		float	operator+(const Fixed &fixed);					/* Addition operator */
		float	operator-(const Fixed &fixed);					/* Subtraction operator */
		float	operator*(const Fixed &fixed);					/* Multiplication operator */
		float	operator/(const Fixed &fixed);					/* Division operator */

		/* Increment/decrement operators */
		Fixed &operator++();									/* Pre-increment operator */
		Fixed operator++(int);									/* Post-increment operator */
		Fixed &operator--();									/* Pre-decrement operator */
		Fixed operator--(int);									/* Post-decrement operator */


		/* Setter/Getter functions */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;							/* Conver fixed-point value to float */
		int		toInt(void) const;								/* Convert fixed point value to int */

		/*--------------------------------------------------*/
		/*			Overloaded Member Functions				*/
		/*--------------------------------------------------*/

		static Fixed &min(Fixed &fixed1, Fixed &fixed2);		/* Return smaller of two fixed points values as reference */
		static const Fixed &min(const Fixed &fixed1,			/* Return smaller of two const fixed points values as const reference */
			const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);		/* Return larger of two fixed points values as reference */
		static const Fixed &max(const Fixed &fixed1,			/* Return larger of two const fixed points values as const reference */
			const Fixed &fixed2);


	private:
		int	fixedValue;
		static const int fractionalBits = 8;					/* Store the number of fractional bits (counting from the right) */
};

/*--------------------------------------------------*/
/*				Non-member Functions				*/
/*--------------------------------------------------*/

std::ostream &operator<<(std::ostream &ostream,					/* Operator overload for << */
	Fixed const & fixed);
int	getPow(int base, int magnitude);							/* Find the power of a number */

#endif