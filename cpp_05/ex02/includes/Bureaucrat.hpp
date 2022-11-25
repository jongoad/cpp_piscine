#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
    public:
    /* Constructors/Destructor */
    Bureaucrat();																/* Default constructor */
    Bureaucrat(const std::string name, unsigned int grade);						/* Name & grade constructor */
    Bureaucrat(const Bureaucrat &bureaucrat);									/* Copy constructor */
    ~Bureaucrat();																/* Destructor */

    /* Operator Overloads */
    Bureaucrat &operator=(const Bureaucrat &other);                             /* Assignement operator overload */

    /* Setters/Getters */
    std::string		getName(void) const;
    void			setName(std::string name);
    unsigned int	getGrade(void) const;

	/* Pubic Member Functions */
	void	increaseGrade(void);
	void	decreaseGrade(void);
    void    signForm(Form& form) const;
    void    executeForm(Form& form) const;

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

    private:
        std::string		name;
        unsigned int	grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);        	/* Insertion operator overload */

#endif