#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>
#include <ctime>
#include <unistd.h>

# include "Zombie.hpp"

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);


#endif