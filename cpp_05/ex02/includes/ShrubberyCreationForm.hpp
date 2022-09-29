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
		ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        /* Operator Overloads */
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;
    private:
        ShrubberyCreationForm();
};

#endif