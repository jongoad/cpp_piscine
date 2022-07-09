#include "../includes/Cat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	this->myBrain = new Brain();
}

/* Copy Constructor */
Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

/* Destructor */
Cat::~Cat() {
	delete this->myBrain;
	std::cout << "Cat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

Cat    &Cat::operator=(const Cat &cat) {
	this->type = cat.type;
	delete this->myBrain;
	this->myBrain = new Brain(*cat.myBrain);
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/
std::string Cat::getIdea(int i) const {
	return (this->myBrain->getIdea(i));
}
void    Cat::setIdea(int i, std::string idea) const {
	this->myBrain->setIdea(i, idea);
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

void    Cat::removeBrain(void) const {
	delete this->myBrain;
}

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/

void	Cat::makeSound(void) const{
	std::cout << "*Meeeeeooooowwwww*" << std::endl;
}

