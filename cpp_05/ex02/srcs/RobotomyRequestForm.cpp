#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

/*------------------------------*/
/*   Constructors/Destructors   */
/*------------------------------*/


/* Target Constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("robotomy", target, 72, 45) {
		std::cout << "Form name constructor called" << std::endl;
}

/* Copy Constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
	: Form("robotomy", other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Form destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

RobotomyRequestForm    &RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
	(void)form;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const RobotomyRequestForm &other) {
	os << "Form name: " << other.getName() << std::endl << "Grade to sign: " << other.getSignGrade() << std::endl
		<< "Grade to execute: " << other.getExecuteGrade() << std::endl << "Signed status: " << other.getIsSigned() << std::endl;
	return (os);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void    RobotomyRequestForm::doAction(const Bureaucrat& input) const {
	this->Form::execute(input);
	std::cout << "*Vzzzzt brrrrrt *" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << this->getTarget() << " has been horribly mangled in an unsuccessfull robotomy attempt!" << std::endl;
}