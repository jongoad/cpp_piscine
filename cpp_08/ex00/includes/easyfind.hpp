#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#pragma once

#include <exception>
#include <algorithm>

class notFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return ("The requested element was not found");
		}
};

template <class T>
typename T::iterator easyfind(T& container, int element);


#endif