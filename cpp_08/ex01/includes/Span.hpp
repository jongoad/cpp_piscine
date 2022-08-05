#ifndef SPAN_HPP
#define SPAN_HPP

#pragma once

#include <exception>
#include <vector>

class Span {
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span &other);
		~Span();

		/* Operator Overloads */
		Span&	operator=(const Span &other);

		/* Public Member Functions */

		void	addNumber(const int num);
		int	shortestSpan(void);
		int	longestSpan(void);

		/* Exceptions */
		class noSpanException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Unable to find span: once or less integers stored");
				}
		};

		class noSpaceException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Unable to add element: span is already full");
				}
		};

	private:

		std::vector<int> store;
		// int *store;							/* Array of ints to store values */
		const unsigned int size;			/* Number of values that can be stored */
		unsigned int countStored;			/* Number of values currently stored */
		int min;							/* Smallest stored value */
		int max;							/* Largest stored value */

};

#endif