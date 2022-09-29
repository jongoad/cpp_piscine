#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "../includes/Animal.hpp"

class Dog : public Animal{
    public:
        /* Constructors & Destructor */
        Dog();
        Dog(std::string const type);
        Dog(Dog const& dog);
        virtual ~Dog();

        /* Operator Overloads */
        Dog& operator=(Dog const& rhs);

        /* Function Overrides */
        void    makeSound(void) const;
};

#endif