#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once

#include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
    /* Constructors/Destructor */
    WrongCat();
    WrongCat(const WrongCat &wrongcat);
    ~WrongCat();

    /* Operator Overloads */
     WrongCat &operator=(const  WrongCat &wrongcat);

    /* Function Overrides */
    private:

    protected:
};

#endif