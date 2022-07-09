#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "../includes/Animal.hpp"

class Dog : public Animal{
    public:
    /* Constructors/Destructor */
    Dog();
    Dog(const Dog &dog);
    ~Dog();

    /* Operator Overloads */
    Dog &operator=(const Dog &dog);

    /* Function Overrides */
    void    makeSound(void) const;

    private:

    protected:
};

#endif