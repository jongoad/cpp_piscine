#ifndef FIXED_HPP
# define FIXED_HPP

#	include <iostream>
#	include <cmath>

class Fixed {
	public:
		/* Constructors & Destructor */
		Fixed();
		Fixed(int const input);
		Fixed(float const input);
		Fixed(Fixed const& other);
		~Fixed();

		/* Operator Overloads */
		Fixed&	operator=(Fixed const& rhs);

		/* Logic Operator Overloads */
		bool	operator>(Fixed const& rhs) const;					/* Greater than operator */
		bool	operator<(Fixed const& rhs) const;					/* Less than operator */
		bool	operator>=(Fixed const& rhs) const;					/* Greater than or equal to operator */
		bool	operator<=(Fixed const& rhs) const;					/* Less than or equal to operator */
		bool	operator==(Fixed const& rhs) const;					/* Equal to operator */
		bool	operator!=(Fixed const& rhs) const;					/* Not equal to operator */
	
		/* Arithmetic Operator Overloads */
		Fixed	operator+(Fixed const& rhs) const;					/* Addition operator */
		Fixed	operator-(Fixed const& rhs) const;					/* Subtraction operator */
		Fixed	operator*(Fixed const& rhs) const;					/* Multiplication operator */
		Fixed	operator/(Fixed const& rhs) const;					/* Division operator */

		/* Increment/Decrement Operator Overloads */
		Fixed&	operator++();										/* Pre-increment operator */
		Fixed	operator++(int);									/* Post-increment operator */
		Fixed&	operator--();										/* Pre-decrement operator */
		Fixed	operator--(int);									/* Post-decrement operator */

		/* Setters & Getters */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* Public Member Functions */
		float	toFloat(void) const;
		int		toInt(void) const;

		/* Overloaded Member Functions */

		static Fixed&		min(Fixed &first, Fixed &second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&		max(Fixed &first, Fixed &second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);

	private:
		int	fixedValue;
		static const int fractionalBits = 8;
};

/*--------------------------------------------------*/
/*				Non-member Functions				*/
/*--------------------------------------------------*/

std::ostream &operator<<(std::ostream &ostream,					/* Operator overload for stream insertion */
	Fixed const & fixed);

int	getPow(int base, int magnitude);							/* Find the power of a number */

#endif