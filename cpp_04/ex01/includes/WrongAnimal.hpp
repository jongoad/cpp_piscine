#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
    /* Constructors/Destructor */
    WrongAnimal();
    WrongAnimal(const WrongAnimal &wronganimal);
    virtual ~WrongAnimal();

    /* Operator Overloads */
    WrongAnimal &operator=(const WrongAnimal &wronganimal);

    /* Public Member Fuctions */
    virtual void    makeSound(void) const;

    /* Setters/Getters */
    std::string getType(void) const;
    
    protected:
        std::string type;
};

#endif