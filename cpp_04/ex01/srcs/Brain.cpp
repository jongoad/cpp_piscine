#include "../includes/Brain.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/
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

// const std::string examples[] = {
// 		"I want to sleep",
// 		"I want food",
// 		"I want pets",
// 		"I want to go for a walk",
// 		"I want water",
// 		"I want a treat"
// 	};
// 	for (int i = 0; i < 100; i++)
// 		this->_ideas[i] = examples[rand() % (sizeof(examples) / sizeof(std::string))];
// 	std::cout << "Brain(void) constructor called" << std::endl;

Brain::Brain(Brain const& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) { this->ideas[i] = other.ideas[i]; }
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/
Brain&	Brain::operator=(Brain const& rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) { this->ideas[i] = rhs.ideas[i]; }
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/
std::string Brain::getIdea(int const i) const { return(this->ideas[i]); }
void	Brain::setIdea(int i, std::string idea) { this->ideas[i] = idea; }