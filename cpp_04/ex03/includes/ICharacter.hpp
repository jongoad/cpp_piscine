#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#pragma once

#include <string>

class AMateria;

class ICharacter
{
    public:
		/* Constructors/Destructor */
		virtual ~ICharacter() {}    

		/* Public Member Functions */
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
