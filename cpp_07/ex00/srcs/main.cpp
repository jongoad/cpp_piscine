#include <iostream>
#include "../includes/Compare.hpp"
#include <string>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"


int main(void) {
   
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
   
    // int a = 5;
    // int b = 9;
    // int c = 5;

    // std::cout << RED"-------------- Testing min -------------" CLEAR << std::endl;
    // std::cout << "Answer should be 5 (a): ";
    // std::cout << min(a, b) << std::endl;

    // std::cout << "Address (a): " << &a << std::endl;
    // std::cout << "Address (c): " << &c << std::endl;

    // std::cout << "Answer should be 5 (c): ";
    // std::cout << &min(a, c) << std::endl;

    // std::cout << std::endl;
    // std::cout << RED"-------------- Testing max -------------" CLEAR << std::endl;
    // std::cout << "Answer should be 9 (b): ";
    // std::cout << max(a, b) << std::endl;

    // std::cout << "Address (a): " << &a << std::endl;
    // std::cout << "Address (c): " << &c << std::endl;

    // std::cout << "Answer should be 5 (c): ";
    // std::cout << &max(a, c) << std::endl;

    // std::cout << std::endl;
    // std::cout << RED"-------------- Testing swap -------------" CLEAR << std::endl;
    // std::cout << "a is: " << a << std::endl;
    // std::cout << "b is: " << b << std::endl;
    // swap(a, b);
    // std::cout << RED"Swapping" CLEAR << std::endl;
    // std::cout << "a is: " << a << std::endl;
    // std::cout << "b is: " << b << std::endl;
}