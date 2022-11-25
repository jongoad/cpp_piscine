#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#pragma once

#include <string>
#include <iostream>

class A_Animal
{
    public:
        /* Constructors & Destructor */
        A_Animal();
        A_Animal(std::string const type);
        A_Animal(A_Animal const& other);
        virtual ~A_Animal();

        /* Operator Overloads */
        A_Animal& operator=(A_Animal const& rhs);

        /* Public Member Fuctions */
        virtual void    makeSound(void) const = 0;

        /* Setters/Getters */
        std::string getType(void) const;
        
    protected:
        std::string type;
};

#endif