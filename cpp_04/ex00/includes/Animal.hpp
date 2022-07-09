#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <string>
#include <iostream>

class Animal
{
    public:
    /* Constructors/Destructor */
    Animal();
    Animal(const Animal &animal);
    virtual ~Animal();

    /* Operator Overloads */
    Animal &operator=(const Animal &animal);

    /* Public Member Fuctions */
    virtual void    makeSound(void) const;

    /* Setters/Getters */
    std::string getType(void) const;
    
    protected:
        std::string type;
};

#endif