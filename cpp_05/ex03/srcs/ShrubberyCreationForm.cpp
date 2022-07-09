#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

/*------------------------------*/
/*   Constructors/Destructors   */
/*------------------------------*/


/* Target Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("shrubbery", target, 145, 137) {
		std::cout << "Form name constructor called" << std::endl;
}

/* Copy Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: Form("shrubbery", other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Form destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	(void)form;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const ShrubberyCreationForm &other) {
	os << "Form name: " << other.getName() << std::endl << "Grade to sign: " << other.getSignGrade() << std::endl
		<< "Grade to execute: " << other.getExecuteGrade() << std::endl << "Signed status: " << other.getIsSigned() << std::endl;
	return (os);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void    ShrubberyCreationForm::doAction(const Bureaucrat& input) const {
	this->Form::execute(input);
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	if (!ofs.is_open())
		throw std::ofstream::failure(strerror(errno));

	ofs << "	oxoxoo    ooxoo" << std::endl;
	ofs << "  ooxoxo oo  oxoxooo" << std::endl;
	ofs << " oooo xxoxoo ooo ooox" << std::endl;
	ofs << " oxo o oxoxo  xoxxoxo" << std::endl;
	ofs << "  oxo xooxoooo o ooo" << std::endl;
	ofs << "    ooo\\oo\\  /o/o" << std::endl;
	ofs << "        \\  \\/ /" << std::endl;
	ofs << "         |   /" << std::endl;
	ofs << "         |  |" << std::endl;
	ofs << "         | D|" << std::endl;
	ofs << "         |  |" << std::endl;
	ofs << "         |  |" << std::endl;
	ofs << "  ______/____\\____" << std::endl;
	ofs.close();
}