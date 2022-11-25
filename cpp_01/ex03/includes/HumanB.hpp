#ifndef HUMANB_HPP
#define HUMANB_HPP

#pragma once

#include "Weapon.hpp"

class HumanB {
	public:
		/* Constructors & Destructor */
		HumanB(std::string const &name);
		~HumanB();

		/* Setters & Getters */
		void setWeapon(Weapon &weapon);

		/* Public Member Functions */
		void attack() const;

	private:
		Weapon*		weapon;
		std::string	name;
};

#endif