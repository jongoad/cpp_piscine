#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

# define INIT_FRAG_HP 100
# define INIT_FRAG_ENERGY 100
# define INIT_FRAG_DAMAGE 30

class FragTrap : public ClapTrap {
	public:
		/* Constructors/Destructors */
		FragTrap();										/* Default Constructor */
		FragTrap(std::string name);						/* Name Constructor */
		FragTrap(const FragTrap &fragtrap);				/* Copy constructor */
		~FragTrap();									/* Destructor */

		/* Operator Overloads */
		FragTrap &operator=(const FragTrap &fragtrap);	/* Copy assignment operator */

		/* Public Member Functions */
		void highFivesGuys(void);

		/* Function Overrides */
		void		attack(const std::string &target);

	private:
};


#endif