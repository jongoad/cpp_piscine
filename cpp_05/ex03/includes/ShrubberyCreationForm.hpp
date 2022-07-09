#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    public:
        /* Constructors/Destructors */
		ShrubberyCreationForm(const std::string& target);																	/* Target Constructor */
        ShrubberyCreationForm(const ShrubberyCreationForm &other);                                                       /* Copy constructor */
        ~ShrubberyCreationForm();                                                                                        /* Destructor */

        /* Operator Overloads */
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        /* Setters/Getters */

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;
    private:
        ShrubberyCreationForm();
};

#endif