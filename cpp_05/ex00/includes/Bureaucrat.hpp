#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once
#include <iostream>
#include <string>

class Bureaucrat
{
    public:
        /* Constructors/Destructor */
        Bureaucrat();
        Bureaucrat(const std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();



        /* Setters/Getters */
        const std::string&  	getName(void) const;
        const unsigned int&     getGrade(void) const;

        /* Pubic Member Functions */
        void	increaseGrade(void);
        void	decreaseGrade(void);

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
        const std::string   name;
        unsigned int        grade;
        Bureaucrat &operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif