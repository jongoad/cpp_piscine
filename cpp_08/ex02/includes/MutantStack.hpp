#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#pragma once

#include <stack>
#include <deque>

template <class T>
class MutantStack
{
    public:
        /* Constructors/Destructor */
        MutantStack();
        MutantStack(const MutantStack<T> &other);
        ~MutantStack();

        /* Operator Overloads */
        MutantStack &operator=(const MutantStack<T> &other);

        /* Public Member Functions */
        bool			empty() const;      /* Return if the stack is empty or not */
        unsigned int	size() const;       /* Return a count of the number of elements in the stack */
        T&				top() const;       /* Return a reference to the top element of the stack */
        void			push(const T& input); /* Insert a new element on the top of the stack, pushing all other elements down */
        void			pop()   const;      /* Remove the top element from the stack */


    private:
		deque<T>	*dat;
		T 				*data;
		unsigned int	elemCount;			/* Current number of elements stored */
        

};

#endif

/*
    template<class Type, class Container=deque<Type> >
    class MutantStack;
*/