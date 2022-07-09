#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "../includes/Animal.hpp"

class Cat : public Animal{
    public:
    /* Constructors/Destructor */
    Cat();
    Cat(const Cat &cat);
    ~Cat();

    /* Operator Overloads */
    Cat &operator=(const Cat &cat);

    /* Function Overrides */
    void    makeSound(void) const;
    private:

    protected:
};

#endif