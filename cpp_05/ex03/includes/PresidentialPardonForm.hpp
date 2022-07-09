#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
    public:
        /* Constructors/Destructors */
		PresidentialPardonForm(const std::string& target);																	/* Target Constructor */
        PresidentialPardonForm(const PresidentialPardonForm &other);                                                       /* Copy constructor */
        ~PresidentialPardonForm();                                                                                        /* Destructor */

        /* Operator Overloads */
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        /* Setters/Getters */

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;
    private:
        PresidentialPardonForm();
};

#endif