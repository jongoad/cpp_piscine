#include "../includes/ClapTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Default Constructor */
ClapTrap::ClapTrap(void) : hitPoints(INIT_HIT_POINTS), initHP(INIT_HIT_POINTS), energyPoints(INIT_ENERGY_POINTS), attackDamage(INIT_ATTACK_DAMAGE) {
	std::cout << "A nameless ClapTrap has been created!" << std::endl;
}

/* Name constructor */
ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(INIT_HIT_POINTS), initHP(INIT_HIT_POINTS), energyPoints(INIT_ENERGY_POINTS), attackDamage(INIT_ATTACK_DAMAGE) {
	std::cout << "A new ClapTrap named " << this->getName() << " has been created!" <<std::endl;
}

/* Copy Constructor */
ClapTrap::ClapTrap(ClapTrap const& other) {
	*this = other;
	std::cout << "ClapTrap " << other.getName() << " has been cloned!" << std::endl;
}

/* Destructor */
ClapTrap::~ClapTrap(void)	{
	std::cout << "ClapTrap " << this->getName() << " has been destroyed!" << std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy Assignment Operator */
ClapTrap &ClapTrap::operator=(ClapTrap const& rhs) {
	this->setName(rhs.name);
	this->setHitPoints(rhs.hitPoints);
	this->setInitHitPoints(rhs.initHP);
	this->setEnergyPoints(rhs.energyPoints);
	this->setAttackDamage(rhs.attackDamage);	
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

/* Perform an attack if enough energy */
void	ClapTrap::attack(const std::string &target) {
	if (this->getEnergyPoints() != 0) {
		this->energyPoints--;
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing "
			<< this->getAttackDamage() << " points of damage!" << std::endl;  
	}
	else
		std::cout << "ClapTrap "<< this->getName() << " does not have enough energy to attack!"
			<< std::endl;
}

/* Take damage and adjust HP, or check for death */
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->getName() << " has taken "
		<< amount << " damage!" << std::endl;
	if ((this->getHitPoints() - amount) <= 0) {
		this->~ClapTrap();
	}
	else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->getName() << " has " << this->getHitPoints() << " hitpoints remaining!"
			<< std::endl;
	}
			
}

/* Perform repair if enough energy */
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() == 0)
		std::cout << "ClapTrap " << this->getName() << " has insufficient energy to repair" << std::endl;
	else if (this->getHitPoints() == this->getInitHitPoints())
		std::cout << "ClapTrap " << this->getName() << "'s hitpoints are already full!" << std::endl;
	else {
		if ((this->getHitPoints() + amount) > static_cast<unsigned int>(this->getInitHitPoints())) {
			int repairAmount = this->getInitHitPoints() - this->getHitPoints();
			this->setHitPoints(this->getInitHitPoints());
			std::cout << "ClapTrap " << this->getName() << " has repaired " <<  repairAmount << " hitpoints!"
			<< " They now have " << this->getHitPoints() << " remaining!" << std::endl;
		}
		else {
			this->hitPoints += amount;
			std::cout << "ClapTrap " << this->getName() << " has repaired " << amount << " hitpoints!"
				<< " They now have " << this->getHitPoints() << " remaining!" << std::endl;
		}
		this->energyPoints--;
	}
}

/*------------------------------*/
/*       Setters/Getters 	    */
/*------------------------------*/

/* Get name */
std::string	ClapTrap::getName(void) const{
	return (this->name);
}

/* Set name */
void	ClapTrap::setName(std::string const name) {
	this->name = name;
}

/* Get hitpoints */
int	ClapTrap::getHitPoints(void) const{
	return (this->hitPoints);
}

/* Set hitpoints */
void	ClapTrap::setHitPoints(int const amount) {
	this->hitPoints = amount;
}
/* Get init hitpoints */
int	ClapTrap::getInitHitPoints(void) const{
	return (this->initHP);
}

/* Set init hitpoints */
void	ClapTrap::setInitHitPoints(int const amount) {
	this->initHP = amount;
}

/* Get energy points */
int	ClapTrap::getEnergyPoints(void) const{
	return (this->energyPoints);
}

/* Set energy points */
void	ClapTrap::setEnergyPoints(int const amount) {
	this->energyPoints = amount;
}

/* Get attack damage */
int	ClapTrap::getAttackDamage(void) const{
	return (this->attackDamage);
}

/* Set attack damage */
void	ClapTrap::setAttackDamage(int amount) {
	this->attackDamage = amount;
}
