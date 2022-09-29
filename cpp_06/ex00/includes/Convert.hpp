#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class Convert {
	public:
		/* Constructors & Destructor */
		Convert(const std::string input);
		Convert(const Convert& other);
		~Convert();

		/* Setters & Getters */

		/* Public Member Functions */
		char	toChar() const;
		int		toInt() const;
		float	toFloat() const;
		double	toDouble() const;

		/* Exceptions */
		class InvalidInput : public std::exception {
			public:
				const char *what() const throw() {
					return ("Input string is empty or invalid!");
				}
		};

		class NonDisplayable : public std::exception {
			public:
				const char *what() const throw() {
					return ("Non displayable");
				}
		};

		class ImpossibleConversion : public std::exception {
			public:
				const char *what() const throw() {
					return ("Impossible conversion");
				}
		};

	private:
		Convert();
		Convert& operator=(const Convert& rhs);
		const std::string	_input;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
		enum inputType {
			charType, 
			intType, 
			floatType, 
			doubleType}		_type;
};

std::ostream& operator<<(std::ostream& os, const Convert& rhs);

#endif