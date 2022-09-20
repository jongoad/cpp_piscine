#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#pragma once

/* System Includes */
#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>

class Zombie {
	public:
		/* Constructors & Destructor */
		Zombie();
		Zombie(const std::string name);
		~Zombie();

		/* Setters & Getters */
		std::string	const&	getName() const;
		void				setName(const std::string name);
		
		/* Public Member Functions */
		void		announce(void);
		void		randomChump(const std::string name);
		
	private:
		std::string name;

};

/* External Functions */
Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif