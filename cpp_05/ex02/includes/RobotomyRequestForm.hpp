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
		RobotomyRequestForm(const std::string& target);																	/* Target Constructor */
        RobotomyRequestForm(const RobotomyRequestForm &other);                                                       /* Copy constructor */
        ~RobotomyRequestForm();                                                                                        /* Destructor */

        /* Operator Overloads */
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        /* Setters/Getters */

		/* Public Member Functions */
        void    doAction(const Bureaucrat& input) const;
    private:
        RobotomyRequestForm();
};

#endif