#include "../includes/FragTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Defualt Constructor */
FragTrap::FragTrap(void) {
	std::cout << "A new FragTrap has been created!" << std::endl;
	this->setHitPoints(INIT_FRAG_HP);
	this->setInitHitPoints(INIT_FRAG_HP);
	this->setEnergyPoints(INIT_FRAG_ENERGY);
	this->setAttackDamage(INIT_FRAG_DAMAGE);
}

/* Name Constructor */
FragTrap::FragTrap(std::string name):  ClapTrap(name){
	std::cout << "A new FragTrap named " << this->getName() << " has been created!" << std::endl;
	this->setHitPoints(INIT_FRAG_HP);
	this->setInitHitPoints(INIT_FRAG_HP);
	this->setEnergyPoints(INIT_FRAG_ENERGY);
	this->setAttackDamage(INIT_FRAG_DAMAGE);
}

/* Copy Constructor */
FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap) {
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = fragtrap;
}

/* Destructor */
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy assignment operator */
FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap copy assignement operator called!" << std::endl;
	this->setName(rhs.getName()); 
	this->setHitPoints(rhs.getHitPoints());
	this->setInitHitPoints(rhs.getInitHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->getName() << " has requested high fives!" << std::endl;
}

/*------------------------------*/
/*       Function Overrides     */
/*------------------------------*/

void	FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << this->getName() << " attacks "
		<< target << " dealing " << this->getAttackDamage() <<
		" points of damage!" << std::endl;
}
