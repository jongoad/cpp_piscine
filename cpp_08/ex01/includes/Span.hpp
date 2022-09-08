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
		void	addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		/* Exceptions */
		class noSpanException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Unable to find span: one or less integers stored");
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
		const unsigned int size;			/* Number of values that can be stored */
};

#endif