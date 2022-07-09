#ifndef ARRAY_HPP
#define ARRAY_HPP

#pragma once

#include <exception>

template <class T>
class Array {
	public:
		Array() : num(0), arr(new T[0]) {};
		Array(unsigned int n) : num(n), arr(new T[n]) {};
		Array(const Array& other);
		~Array();

		/* Operator Overloads */
		Array&	operator=(const Array &other);
		T&		operator[](unsigned int n);

		/* Public Member Functions */
		unsigned int size(void);

		/* Exceptions */
		class invalidIndex : public std::exception {
			public:
				const char *what() const throw() {
					return ("Index value is out of range");
				}
		};
		
	private:
		unsigned int num;
		T* arr;

};

#endif