#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "../includes/Animal.hpp"

class Cat : public Animal{
    public:
        /* Constructors & Destructor */
        Cat();
        Cat(std::string const type);
        Cat(Cat const& other);
        virtual ~Cat();

        /* Operator Overloads */
        Cat& operator=(Cat const& rhs);

        /* Function Overrides */
        void    makeSound(void) const;
};

#endif