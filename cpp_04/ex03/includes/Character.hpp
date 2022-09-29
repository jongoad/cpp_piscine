#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
		/* Constructors & Destructor */
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		~Character();

		/* Operator Overloads */
		Character&	operator=(const Character& rhs);

		/* Public Member Functions */
		std::string const& 	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		
    private:
			AMateria 	*inventory[4];
			std::string name;
};

#endif