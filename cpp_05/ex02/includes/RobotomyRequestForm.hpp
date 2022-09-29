#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
    public:
        /* Constructors/Destructors */
		RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        /* Operator Overloads */
        RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;

    private:
        RobotomyRequestForm();
};

#endif