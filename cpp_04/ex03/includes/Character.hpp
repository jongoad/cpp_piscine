#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:

		/* Constructors/Destructor */
		Character();                                            /* Default Constructor */
		Character(const std::string &name);						/* Name Constructor */
		Character(const Character &character);                  /* Copy Constructor */
		~Character();											/* Destructor */

		/* Operator Overloads */
		Character &operator=(const Character &character);

		/* Public Member Functions */
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
    private:
			AMateria 	*inventory[4];
			std::string name;
			AMateria	**discard;
			int			numberDiscarded;
};

#endif
