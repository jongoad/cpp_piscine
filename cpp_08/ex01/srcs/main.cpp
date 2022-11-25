#include <iostream>
#include <string>
#include <vector>
#include "../includes/Span.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|           Span Tester          |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"--------------Testing Provided Code-------------" CLEAR << std::endl << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << RED"--------------Testing Exceptions-------------" CLEAR << std::endl << std::endl;
	Span test1(3);

	/* Test with empty span */
	std::cout << RED"-----Testing with Empty Span-----" CLEAR << std::endl;
	try {
		std::cout << "Shortest span: " << test1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << test1.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* Test with only one value */
	std::cout << RED"-----Testing with Only One Value Stored-----" CLEAR << std::endl;
	try {
		test1.addNumber(1);
		std::cout << "Shortest span: " << test1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << test1.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* Test with more than one value */
	std::cout << RED"-----Testing with Multiple Values Stored-----" CLEAR << std::endl;
	try {
		test1.addNumber(3);
		std::cout << "Shortest span: " << test1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << test1.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* Test adding too many values */
	std::cout << RED"-----Testing with Adding Too Many Values-----" CLEAR << std::endl;
	try {
		test1.addNumber(5);
		std::cout << "Shortest span: " << test1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test1.longestSpan() << std::endl;
		test1.addNumber(7);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << test1.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << RED"--------------Testing Adding via Iterator Range--------------" CLEAR << std::endl << std::endl;

	/* Create vector to pass iterator range from */
	std::vector<int> vec;
	for (int i = 1; i < 4; i++) {
		vec.push_back(i * i);
	}

	Span test2(3);
	Span test3(2);

	try {
		test2.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span is: " << test2.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << test2.longestSpan() << std::endl;

		test3.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span is: " << test3.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << test3.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	/* Show that values were still added with exception thrown */
	try {
		std::cout << "Shortest span is: " << test3.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << test3.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << RED"--------------Testing with Large Spans--------------" CLEAR << std::endl << std::endl;

	std::vector<int> vec2;
	for (int i = 0; i < 25000; i++) {
		vec2.push_back(i * i);
	}
	Span test4(25000);

	try {
		test4.addNumber(vec2.begin(), vec2.end());
		std::cout << "Shortest span is: " << test4.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << test4.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}
