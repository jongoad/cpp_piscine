#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    public:
        /* Constructors/Destructors */
		Form(const std::string& name);																	/* Name constructor */
        Form(const std::string& name, const unsigned int signgrade, const unsigned int executegrade);   /* Full constructor */
        Form(const Form &form);                                                                         /* Copy constructor */
        ~Form();                                                                                        /* Destructor */

        /* Operator Overloads */
        Form &operator=(const Form &form);

        /* Setters/Getters */
        std::string		getName(void) const;
        void    		setIsSigned(const bool issigned) const;
        bool			getIsSigned(void) const;
    	unsigned int	getSignGrade(void) const;
        unsigned int	getExecuteGrade(void) const;
		
		/* Public Member Functions */
		void	beSigned(const Bureaucrat& input);

        /* Exceptions */
        class gradeLowException : public std::exception {
            public:
                const char *what() const throw() {
                    return ("Grade too low!");
                }
        };

        class gradeHighException : public std::exception {
            public:
                const char *what() const throw() {
                    return ("Grade too high!");
                }
        };

		class alreadySignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Form is already signed!");
				}
		};

    private:
        Form() : name(""), isSigned(false), signGrade(1), executeGrade(1) {};        /* Default constructor */

        const std::string   name;
        bool                isSigned;
        const unsigned int  signGrade;
        const unsigned int  executeGrade;
};

std::ostream    &operator<<(std::ostream &os, const Form &other);

#endif