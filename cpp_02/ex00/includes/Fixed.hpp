#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once

#include <iostream>

class Fixed {
	public:
		/* Constructors & Destructor */
		Fixed();
		Fixed(Fixed const& other);
		~Fixed();

		/* Operator Overloads */
		Fixed & operator=(Fixed const& rhs);

		/* Public Member Functions */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	fixedValue;
		static const int fractionalBits = 8;		/* Store the number of fractional bits (counting from the right) */

};

#endif