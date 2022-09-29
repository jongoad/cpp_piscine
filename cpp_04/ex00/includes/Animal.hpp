#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <string>
#include <iostream>

class Animal
{
    public:
        /* Constructors & Destructor */
        Animal();
        Animal(std::string const type);
        Animal(Animal const& other);
        virtual ~Animal();

        /* Operator Overloads */
        Animal& operator=(Animal const& rhs);

        /* Public Member Fuctions */
        virtual void    makeSound(void) const;

        /* Setters/Getters */
        std::string getType(void) const;
        
    protected:
        std::string type;
};

#endif