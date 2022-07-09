#include "../includes/Intern.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

/* Copy Constructor */
Intern::Intern(const Intern &intern) {
	*this = intern;
	std::cout << "Intern copy contructor called" << std::endl;
}

/* Destructor */
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/
Intern    &Intern::operator=(const Intern &intern) {
	if (&intern != this)
		return (*this);
	else
		return (*this);

}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/
Form    *Intern::makeForm(const std::string name, const std::string target) {
	const std::string formTypes[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	int i = 0;
	for (; i < 3; i++) {
		if (name == formTypes[i])
			break;
	}
	Form *result = NULL;
	switch (i)
	{
		case 0:
			result = new ShrubberyCreationForm(target);
			break;
		case 1:
			result = new PresidentialPardonForm(target);
			break;
		case 2:
			result = new RobotomyRequestForm(target);
			break;
		default:
			throw Intern::invalidFormException();
	}
	std::cout << "Intern creates " << result->getName() << std::endl;
	return (result);
}