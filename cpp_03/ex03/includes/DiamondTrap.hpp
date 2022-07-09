#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		/* Constructors/Destructors */
		DiamondTrap();											/* Default Constructor */
		DiamondTrap(std::string name);							/* Name Constructor */
		DiamondTrap(const DiamondTrap &diamondtrap);			/* Copy Constructor */
		~DiamondTrap();											/* Destructor */

		/* Operator Overloads */
		DiamondTrap &operator=(const DiamondTrap &diamondtrap);

		/* Public Member Functions */
		void 	whoAmI(void);
		void	attack(const std::string &target);

		/* Setters/Getters */
		std::string	getLocalName(void) const;

	private:
		/* Private Attributes */
		std::string name;

};


#endif
