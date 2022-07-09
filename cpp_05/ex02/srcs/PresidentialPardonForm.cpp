#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

/*------------------------------*/
/*   Constructors/Destructors   */
/*------------------------------*/


/* Target Constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("presidential pardon", target, 25, 5) {
		std::cout << "Form name constructor called" << std::endl;
}

/* Copy Constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: Form("presidential pardon", other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Form destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

PresidentialPardonForm    &PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
	(void)form;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const PresidentialPardonForm &other) {
	os << "Form name: " << other.getName() << std::endl << "Grade to sign: " << other.getSignGrade() << std::endl
		<< "Grade to execute: " << other.getExecuteGrade() << std::endl << "Signed status: " << other.getIsSigned() << std::endl;
	return (os);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void    PresidentialPardonForm::doAction(const Bureaucrat& input) const {
	this->Form::execute(input);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}