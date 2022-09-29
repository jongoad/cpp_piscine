#include "../includes/Convert.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/
Convert::Convert(const std::string input) : _input(input) {
	if (input.empty())
		throw Convert::InvalidInput();
	else if (input.size() == 1) {
		if (isdigit(_input.front()))
			this->_int = static_cast<int>(strtol(input.c_str(), NULL, 10));
		else
			this->_char = input.front();
			this->_type = charType;
	}
	else {
		char	*longRemain;														/* Get remainder of string after long */
		long	longPart = strtol(input.c_str(), &longRemain, 10);					/* Store long value created by strtol */
		char	*decimalRemain;														/* Get remainder of string after float */
		double	doublePart = strtod(input.c_str(), &decimalRemain);					/* Store float value created by strtof */

		if (*longRemain) {															/* If anything remains in string after long */
			if (*decimalRemain)	{													/* If anything remains in string after float, check if 'f' char */
				if (*decimalRemain == 'f') {
					this->_float = static_cast<float>(doublePart);
					this->_type = floatType;
				}
				else																/* If not 'f' char then throw exception */
					throw Convert::InvalidInput();
			}
			else {																	/* If no remain, set double val */
				this->_double = doublePart;
				this->_type = doubleType;
			}
		}
		else {																		/* If no decimal part, check long value */	
			if (longPart > std::numeric_limits<int>::max()							/* If out of int limit range, throw exception */
				|| longPart < std::numeric_limits<int>::min())
				throw Convert::InvalidInput();
			else
				this->_int = static_cast<int>(longPart);
				this->_type = intType;
		}
	}
}

Convert::Convert(const Convert& other) : _input(other._input) { *this = other; }
Convert::~Convert() {}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

char	Convert::toChar() const {
	char c;
	switch (this->_type) {
		case charType:
			return this->_char;
		case intType:
			c = static_cast<char>(this->_int);
			if (!isprint(c))
				throw Convert::NonDisplayable();
			else
				return (c);
		case floatType:
			c = static_cast<float>(this->_float);
			if (isnan(this->_float) || isinf(this->_float) 
				|| this->_float > std::numeric_limits<char>::max()
				|| this->_float < std::numeric_limits<char>::min())
				throw Convert::ImpossibleConversion();
			else if (!isprint(c))
				throw Convert::NonDisplayable();
			else
				return (c);
		case doubleType:
			c = static_cast<float>(this->_double);
			if (isnan(this->_double) || isinf(this->_double) 
				|| this->_double > std::numeric_limits<char>::max()
				|| this->_double < std::numeric_limits<char>::min())
				throw Convert::ImpossibleConversion();
			else if (!isprint(c))
				throw Convert::NonDisplayable();
			else
				return (c);

		default:
			break;

	}
}

int		Convert::toInt() const {
	switch (this->_type) {
		case charType:
			return (static_cast<int>(this->_char));
		case intType:
			return (this->_int);
		case floatType:
			if (isnan(this->_float) || isinf(this->_float) 
				|| this->_float > std::numeric_limits<int>::max()
				|| this->_float < std::numeric_limits<int>::min())
				throw Convert::ImpossibleConversion();
			else
				return (static_cast<int>(this->_float));
		case doubleType:
			if (isnan(this->_double) || isinf(this->_double) 
				|| this->_double > std::numeric_limits<int>::max()
				|| this->_double < std::numeric_limits<int>::min())
				throw Convert::ImpossibleConversion();
			else
				return (static_cast<int>(this->_double));
		default:
			break;

	}
}

float	Convert::toFloat() const {
	switch (this->_type) {
		case charType:
			return (static_cast<float>(this->_char));
		case intType:
			return (static_cast<float>(this->_int));
		case floatType:
			return (this->_float);
		case doubleType:
			return (static_cast<float>(this->_double));
		default:
			break;
	}
}

double	Convert::toDouble() const {
	switch (this->_type) {
		case charType:
			return (static_cast<float>(this->_char));
		case intType:
			return (static_cast<float>(this->_int));
		case floatType:
			return (static_cast<double>(this->_float));
		case doubleType:
			return (this->_double);
		default:
			break;
	}
}


/*------------------------------*/
/*       Operator Overloads     */
/*------------------------------*/
Convert&	Convert::operator=(const Convert& rhs) { (void)rhs; return (*this); }

std::ostream& operator<<(std::ostream& os, const Convert& rhs) {
	os << "char: ";
	try {
		char c = rhs.toChar();
		os << "'" << c << "'" << std::endl;
	}
	catch (const std::exception& e) {
		os << e.what() << std::endl;
	}
	os << "int: ";
	try {
		int i = rhs.toInt();
		os << i << std::endl;
	}
	catch (const std::exception& e) {
		os << e.what() << std::endl;
	}
	os << "float: ";
	try {
		float f = rhs.toFloat();
		double whole;
		if (modf(f, &whole) == 0)
			os.precision(1);
		os << std::fixed <<  f << "f" << std::endl;
	}
	catch (const std::exception& e) {
		os << e.what() << std::endl;
	}
	os << "double: ";
	try {
		double d = rhs.toDouble();
		double whole;
		if (modf(d, &whole) == 0)
			os.precision(1);
		os << std::fixed << d << std::endl;
	}
	catch (const std::exception& e) {
		os << e.what() << std::endl;
	}
	return (os);
}