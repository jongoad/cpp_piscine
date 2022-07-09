#ifndef CONVERT_HPP
#define CONVERT_HPP

#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <ctype.h>
#include <stdlib.h>

class Convert
{
    public:
        /* Constructors/Destructor */
        Convert();
        Convert(const std::string &input);
        Convert(const Convert &convert);
        ~Convert();

        /* Operator Overloads */
        Convert &operator=(const Convert &convert);

        /* Public Member Functions */
        void	checkInput();
		void	printOutput(void);
        bool	isChar(void);
        bool	isPrintable(const char c);
        bool	isPseudoFloat(void);
        bool	isPseudoDouble(void);
        bool	isFloat(void);
        bool	isDouble(void);
        bool	isInt(void);

		void	convertChar(void);
		void	convertFloat(void);
		void	convertDouble(void);
		void	convertInt(void);


        void    printConverted(void);

        /* Exceptions */
        class emptyException : public std::exception {
            public:
                const char *what() const throw() {
					return ("Input string is empty!");
				}
        };

        class invalidException : public std::exception {
            public:
                const char *what() const throw() {
					return ("Input string is not valid!");
				}
        };

    private:
        std::string	inputString;
		bool		isPseudo;
		char		type;
        char		charVal;
        int			intVal;
        float		floatVal;
        double		doubleVal;
};

#endif