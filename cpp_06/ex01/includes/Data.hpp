#ifndef DATA_HPP
#define DATA_HPP

#pragma once

#include <string>
#include <iostream>

typedef struct
{
	std::string     firstName;
	std::string     lastName;
	std::string		favColour;
	unsigned int    age;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif