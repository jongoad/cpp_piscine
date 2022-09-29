#include "../includes/Bureaucrat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/
Bureaucrat::Bureaucrat() : name("default") { std::cout << "Bureaucrat default constructor called" << std::endl; }

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name) {
	std::cout << "Bureaucrat name & grade constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::gradeHighException();
	else if (grade > 150)
		throw Bureaucrat::gradeLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

/* Assignment operator overload */
Bureaucrat    &Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

/* Insert operator overload */
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade: " << rhs.getGrade();
	return (os);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

const unsigned int&	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

void	Bureaucrat::increaseGrade(void) {
	if (this->grade == 1)
		throw Bureaucrat::gradeHighException();
	else
		this->grade--;
}

void	Bureaucrat::decreaseGrade(void) {
	if (this->grade == 150)
		throw Bureaucrat::gradeLowException();
	else
		this->grade++;
}