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
		Form(const std::string& name);																	
		Form(const std::string& name, const std::string& target);																	
        Form(const std::string& name, const unsigned int signgrade, const unsigned int executegrade);
        Form(const std::string& name, const std::string& target, const unsigned int signgrade, const unsigned int executegrade);
        Form(const Form &other);
        virtual ~Form();

        /* Operator Overloads */
        Form &operator=(const Form &form);

        /* Setters/Getters */
        std::string		getName(void) const;
        bool			getIsSigned(void) const;
    	unsigned int	getSignGrade(void) const;
        unsigned int	getExecuteGrade(void) const;
        void            setIsSigned(const bool issigned);
        std::string		getTarget(void) const;
 
		
		/* Public Member Functions */
		void	        beSigned(const Bureaucrat& input);
        virtual void    doAction(const Bureaucrat& input) const = 0;
        void            execute(const Bureaucrat& input) const;

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

		class notSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Form has not been signed!");
				}
		};

    private:
        Form() : name(""), target(""), isSigned(false), signGrade(1), executeGrade(1) {};        /* Default constructor */

        const std::string   name;
        const std::string   target;
        bool                isSigned;
        const unsigned int  signGrade;
        const unsigned int  executeGrade;
};

std::ostream    &operator<<(std::ostream &os, const Form &other);

#endif