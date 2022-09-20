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

		/* Setters & Getters */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* Public Member Functions */
		float	toFloat(void) const;
		int		toInt(void) const;

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