#include "../includes/Brain.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/

/* Default Constructor */
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (i < 33)
			this->ideas[i] = "FOOD!";
		else if (i >=33 && i < 66)
			this->ideas[i] = "PLAY!";
		else if (i >= 66)
			this->ideas[i] = "SLEEP!";
	}
}

/* Copy Constructor */
Brain::Brain(const Brain &brain) {
	*this = brain;
	std::cout << "Brain copy constructor called" << std::endl;
}

/* Destructor */
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Brain    &Brain::operator=(const Brain &brain) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

std::string Brain::getIdea(int i) const {
	return(this->ideas[i]);
}

void	Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

