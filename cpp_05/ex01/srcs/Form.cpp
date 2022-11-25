#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

/*------------------------------*/
/*   Constructors/Destructors   */
/*------------------------------*/

/* Default Constructor */
// Form::Form() {

// }
/* Name constructor */
Form::Form(const std::string& name)
	: name(name), isSigned(false), signGrade(1), executeGrade(1) {
		std::cout << "Form name constructor called" << std::endl;
}
/* Full Constructor */
Form::Form(const std::string& name ,const unsigned int signgrade, const unsigned int executegrade)
	: name(name), isSigned(false), signGrade(signgrade), executeGrade(executegrade) {
		std::cout << "Form full constructor called" << std::endl;
}

/* Copy Constructor */
Form::Form(const Form &form)
	: name(form.name), isSigned(form.isSigned), signGrade(form.signGrade), executeGrade(form.executeGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

/* Destructor */
Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

Form    &Form::operator=(const Form &rhs) {
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Form &other) {
	os << "Form name: " << other.getName() << std::endl << "Grade to sign: " << other.getSignGrade() << std::endl
		<< "Grade to execute: " << other.getExecuteGrade() << std::endl << "Signed status: " << other.getIsSigned() << std::endl;
	return (os);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/
std::string	Form::getName(void) const {
	return (this->name);
}

bool	Form::getIsSigned(void) const {
	return(this->isSigned);
}

unsigned int	Form::getSignGrade(void) const {
	return(this->signGrade);
}

unsigned int	Form::getExecuteGrade(void) const {
	return(this->executeGrade);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void	Form::beSigned(const Bureaucrat& input){
	if (!this->isSigned) {
		if (input.getGrade() <= this->signGrade)
			this->isSigned = true;
		else
			throw Form::gradeLowException();
	}
	else
		throw Form::alreadySignedException();
}
