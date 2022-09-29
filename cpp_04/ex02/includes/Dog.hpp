#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "../includes/A_Animal.hpp"
#include "../includes/Brain.hpp"

class Dog : public A_Animal{
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

        /* Setters & Getters */
        Brain*   getBrain(void);

        private: 
            Brain *brain;
};

#endif