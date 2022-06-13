#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();									/* Default constructor */
		Fixed(const Fixed &fixed);					/* Copy constructor */
		~Fixed();									/* Destructor */
		Fixed & operator = (const Fixed &fixed);	/* Copy assignment operator */


		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	fixedValue;
		static const int bits = 8;

};

#endif