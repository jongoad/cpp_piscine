#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#pragma once

#include <string>
#include <iostream>

class Zombie {
	public:
		/* Constructors & Destructors */
		Zombie(std::string name);
		~Zombie();

		/* Public Member Functions */
		void		announce(void) const;
		std::string	getName() const;

	private:
		std::string name;
};

/* External Functions */
Zombie	*newZombie(const std::string name);
void	randomChump(const std::string name);

#endif