#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once

#include <string>

class Form;

class Intern
{
    public:
    /* Constructors/Destructor */
        Intern();
        Intern(const Intern &intern);
        ~Intern();

    /* Operator Overloads */
        Intern &operator=(const Intern &intern);

    /* Public Member Functions */
        Form    *makeForm(const std::string name, const std::string target);

    class invalidFormException : public std::exception {
        public:
            const char *what() const throw() {
                return("The requested form type does not exist!");
            }
    };
};

#endif