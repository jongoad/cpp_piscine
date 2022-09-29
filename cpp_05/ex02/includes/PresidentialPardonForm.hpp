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
		PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        /* Operator Overloads */
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;

    private:
        PresidentialPardonForm();
};

#endif