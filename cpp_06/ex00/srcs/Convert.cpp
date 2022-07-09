#include "../includes/Convert.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Convert::Convert() {
}

Convert::Convert(const std::string &input) : inputString(input){
	this->isPseudo = false;
	try {
		this->checkInput();
		switch (this->type) {
		case 'c':
			this->convertChar();
			break;
		case 'f':
			this->convertFloat();
			break;
		case 'd':
			this->convertDouble();
			break;
		case 'i':
			this->convertInt();
			break;
		default:
			break;
		}
		this->printOutput();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

/* Copy Constructor */
Convert::Convert(const Convert &convert) {
	*this = convert;
}

/* Destructor */
Convert::~Convert() {
}

/*------------------------------*/
/*       Operator Overloads     */
/*------------------------------*/

Convert    &Convert::operator=(const Convert &convert) {
	this->inputString = convert.inputString;
	this->type = convert.type;
	this->charVal = convert.charVal;
	this->floatVal = convert.floatVal;
	this->doubleVal = convert.doubleVal;
	this->intVal = convert.intVal;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

/* Check input and convert to proper type */
void	Convert::checkInput(void) {
	if (this->inputString.empty())							/* Check empty string */
		throw Convert::emptyException();
	else if (this->isChar())								/* Check if single char */
		this->type = 'c';
	else if (this->isPseudoDouble() || this->isDouble())	/* Check if pseudo double or double match */
		this->type = 'd';
	else if (this->isPseudoFloat() || this->isFloat())		/* Check if pseudo float or float match */
		this->type = 'f';
	else if (this->isInt())									/* Check if int match */
		this->type = 'i';
	else
		throw Convert::invalidException();
}

void	Convert::printOutput(void) {
	/* Print char */
	std::cout << "char: ";
	if (this->isPseudo)
		std::cout << "Impossible conversion" << std::endl;
	else if (this->isPrintable(this->charVal))
		std::cout << "\'" << this->charVal << "\'" << std::endl;
	else
		std::cout << "Not a printable char" << std::endl;

	/* Print int */
	std::cout << "int: ";
	if (this->isPseudo)
		std::cout << "Impossible conversion" << std::endl;
	else
		std::cout << this->intVal << std::endl;
	
	/* Print float */
	std::cout << "float: " << this->floatVal << "f" << std::endl;

	/* Print double */
	std::cout << "double: " << this->doubleVal << std::endl;	
}

/* Check if a character belongs to the printable set */
bool    Convert::isPrintable(const char c) {
	if (c >= 32 && c <= 125)
		return (true);
	else
		return (false);
}

/* Check if string contains a single char */
bool	Convert::isChar(void) {
	if (this->inputString.length() == 1 && !isdigit(this->inputString.front())) {
		this->charVal = this->inputString.front();
		return (true);
	}
	return (false);
}


/* Check if input is a pseudo float literal value */
bool	Convert::isPseudoFloat(void) {
	std::string pseudo[] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++) {
		if (this->inputString == pseudo[i]) {
			switch (i) {
				case 0:
					this->floatVal = -INFINITY;
					break;
				case 1:
					this->floatVal = INFINITY;
					break;
				case 2:
					this->floatVal = NAN;
					break;
				default:
					break;
			}
			this->isPseudo = true;
			return (true);
		}
	}
	return (false);
}
/* Check if input is a pseudo double literal value */
bool	Convert::isPseudoDouble(void) {
	std::string pseudo[] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++) {
		if (this->inputString == pseudo[i]) {
			switch (i) {
				case 0:
					this->doubleVal = -INFINITY;
					break;
				case 1:
					this->doubleVal = INFINITY;
					break;
				case 2:
					this->doubleVal = NAN;
					break;
				default:
					break;
			}
			this->isPseudo = true;
			return (true);
		}
	}
	return (false);
}

/* Check if input is a valid float */
bool    Convert::isFloat(void) {
	int invalid = this->inputString.find_first_not_of("-+0123456789.fF");
	if (invalid != -1)																			/* Check for invalid chars */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '.') > 1)			/* Check for duplicate periods */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '-') > 1)			/* Check for duplicate negative */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '+') > 1)			/* Check for duplicate positive */
		return (false);
	else if ((this->inputString.front() == '-' || this->inputString.front() == '+')				/* Check for duplicate signs */
		&& (!isdigit(this->inputString[1]) && this->inputString[1] != '.'))
		return (false);
	else if ((this->inputString.back() == 'f' || this->inputString.back() == 'F')				/* Check for extra alpha chars */
		&& isalpha(this->inputString[this->inputString.length() - 2]))
		return (false);
	char *ptr;
	this->floatVal = strtof(this->inputString.c_str(), &ptr);
	return (true);
}

/* Check if input is a valid double */
bool	Convert::isDouble(void) {
	int invalid = this->inputString.find_first_not_of("-+0123456789.");
	if (invalid != -1)																			/* Check for invalid chars */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '.') > 1)			/* Check for duplicate periods */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '-') > 1)			/* Check for duplicate negative */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '+') > 1)			/* Check for duplicate positive */
		return (false);
	else if ((this->inputString.front() == '-' || this->inputString.front() == '+')				/* Check for duplicate signs */
		&& (!isdigit(this->inputString[1]) && this->inputString[1] != '.'))
		return (false);
	char *ptr;
	this->doubleVal = strtod(this->inputString.c_str(), &ptr);
	return (true);
}

/* Check if input is a valid int */
bool	Convert::isInt(void) {
	int invalid = this->inputString.find_first_not_of("-+0123456789");
	if (invalid != -1)																			/* Check for invalid chars */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '-') > 1)			/* Check for duplicate negative */
		return (false);
	else if (std::count(this->inputString.begin(), this->inputString.end(), '+') > 1)			/* Check for duplicate positive */
		return (false);
	else if ((this->inputString.front() == '-' || this->inputString.front() == '+')				/* Check for duplicate signs */
		&& (!isdigit(this->inputString[1]) && this->inputString[1] != '.'))
		return (false);
	this->intVal = atoi(this->inputString.c_str());
	return (true);
}

/* Convert from char */
void	Convert::convertChar(void) {
	this->floatVal = static_cast<float>(this->charVal);
	this->doubleVal = static_cast<double>(this->charVal);
	this->intVal = static_cast<int>(this->charVal);
}

/* Convert from float */
void	Convert::convertFloat(void) {
	this->doubleVal = static_cast<double>(this->floatVal);
	this->charVal = static_cast<char>(this->floatVal);
	this->intVal = static_cast<int>(this->floatVal);
}

/* Convert from double */
void	Convert::convertDouble(void) {
	this->charVal = static_cast<char>(this->doubleVal);
	this->floatVal = static_cast<float>(this->doubleVal);
	this->intVal = static_cast<int>(this->doubleVal);
}

/* Convert from int */
void	Convert::convertInt(void) {
	this->charVal = static_cast<char>(this->intVal);
	this->floatVal = static_cast<float>(this->intVal);
	this->doubleVal = static_cast<double>(this->intVal);
}