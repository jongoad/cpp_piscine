#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once
#include <string>
#include <iostream>

class Brain
{
    public:
    /* Constructors/Destructor */
    Brain();
    Brain(const Brain &brain);
    ~Brain();

    /* Operator Overloads */
    Brain &operator=(const Brain &brain);

    /* Setters/Getters */
    std::string getIdea(int i) const;
    void    setIdea(int i, std::string idea);

    private:

    protected:
        std::string ideas[100];
};

#endif