#include "../includes/Cat.hpp"

/*------------------------------*/
/*  Constructors & Destructor   */
/*------------------------------*/
Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const type) : Animal(type), brain(new Brain()) {
	std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/
Cat&	Cat::operator=(Cat const& rhs) {
	std::cout << "Cat copy assignement operator called" << std::endl;
	this->type = rhs.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/
void	Cat::makeSound(void) const{ std::cout << "*Meeeeeooooowwwww*" << std::endl; }

/*------------------------------*/
/*       Setters & Getters      */
/*------------------------------*/

Brain*	Cat::getBrain(void) { return (this->brain); }
