#include "../includes/FragTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Defualt Constructor */
FragTrap::FragTrap(void) {
	std::cout << "A new FragTrap has been created!"
		<< std::endl;
	this->setAttackDamage(INIT_FRAG_DAMAGE);
	this->setEnergyPoints(INIT_FRAG_ENERGY);
	this->setHitPoints(INIT_FRAG_HP);
}

/* Name Constructor */
FragTrap::FragTrap(std::string name):  ClapTrap(name){
	this->setAttackDamage(INIT_FRAG_DAMAGE);
	this->setEnergyPoints(INIT_FRAG_ENERGY);
	this->setHitPoints(INIT_FRAG_HP);
	std::cout << "A new FragTrap named " << this->getName()
		<< " has been created!" << std::endl;
}

/* Copy Constructor */
FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap) {
	std::cout << "FragTrap copy constructor called!"
		<< std::endl;
	*this = fragtrap;
}

/* Destructor */
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->getName() << " has been destroyed!"
		<< std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy assignment operator */
FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	this->setName(fragtrap.getName()); 
	this->setHitPoints(fragtrap.getHitPoints());
	this->setEnergyPoints(fragtrap.getEnergyPoints());
	this->setAttackDamage(fragtrap.getAttackDamage());
	std::cout << "FragTrap copy assignement operator called!"
		<< std::endl;
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() <<
		" has requested high fives!" << std::endl;
}

/*------------------------------*/
/*       Function Overrides     */
/*------------------------------*/

void	FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << this->getName() << " attacks "
		<< target << " dealing " << this->getAttackDamage() <<
		" points of damage!" << std::endl;
}
