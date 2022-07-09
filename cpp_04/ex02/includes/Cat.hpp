#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

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

    /* Setters/Getters */
    std::string getIdea(int i) const;
    void    setIdea(int i, std::string idea) const;

    /* Public Member Functions */
    void    removeBrain(void) const;
    
    private:
        Brain   *myBrain;
    protected:
};

#endif