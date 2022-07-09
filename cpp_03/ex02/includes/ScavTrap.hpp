#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define INIT_SCAV_HP 100
# define INIT_SCAV_ENERGY 50
# define INIT_SCAV_DAMAGE 20

class ScavTrap : public ClapTrap {
	public:
	
		/* Constructors/Destructors */
		ScavTrap();											/* Default Constructor */
		ScavTrap(std::string name);							/* Name constructor */
		ScavTrap(const ScavTrap &scavtrap);					/* Copy constructor */
		~ScavTrap();										/* Destructor */

		/* Operator Overloads */
		ScavTrap	&operator=(const ScavTrap &scavtrap);		/* Copy assignment operator */

		/* Public Member Functions */
		void 		guardGate(void);

		/* Function Overrides */
		void		attack(const std::string &target);


	private:
		/* Private attributes */
		bool guardingGate;
};


#endif




