#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

/* Name & Grade Constructor */
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name) {
	std::cout << "Bureaucrat name & grade constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::gradeHighException();
	else if (grade > 150)
		throw Bureaucrat::gradeLowException();
	else
		this->grade = grade;
}

/* Copy Constructor */
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

/* Destructor */
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

/* Assignment operator overload */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->name = rhs.name;
	this->grade = rhs.grade;
	return (*this);
}

/* Insert operator overload */
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other) {
	os << other.getName() << ", bureaucrat grade: " << other.getGrade();
	return (os);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

void	Bureaucrat::setName(const std::string name) {
	this->name = name;
}

std::string Bureaucrat::getName(void) const {
	return (this->name);
}

unsigned int Bureaucrat::getGrade(void) const {
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

void	Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}	