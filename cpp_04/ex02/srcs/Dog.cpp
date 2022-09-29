#include "../includes/Dog.hpp"

/*------------------------------*/
/*  Constructors & Destructor   */
/*------------------------------*/
Dog::Dog() : A_Animal ("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const type) : A_Animal(type), brain(new Brain()) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(Dog const& other) : A_Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/
Dog&	Dog::operator=(Dog const& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/
void	Dog::makeSound(void) const{ std::cout << "*Bark Bark*" << std::endl; }


/*------------------------------*/
/*       Setters & Getters      */
/*------------------------------*/
Brain*	Dog::getBrain(void) { return (this->brain); }