#include "easyfind.hpp"

template <class T>
typename T::iterator easyfind(T& container, int element) {
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	if (it != container.end())
		return (it);
	else
		throw notFoundException();
}