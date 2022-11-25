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
        Bureaucrat();
        Bureaucrat(const std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &other);	
        ~Bureaucrat();

        /* Operator Overloads */
        Bureaucrat &operator=(const Bureaucrat& rhs);

        /* Setters/Getters */
        std::string		getName(void) const;
        void			setName(const std::string name);
        unsigned int	getGrade(void) const;

        /* Pubic Member Functions */
        void	increaseGrade(void);
        void	decreaseGrade(void);
        void    signForm(Form& form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif