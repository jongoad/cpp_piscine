#include <iostream>
#include "../includes/Array.hpp"
#include "../includes/Array.tpp"

#define MAX_VAL 750

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int main(int, char**)
{
    std::cout << RED"-------------- Testing Provided Code -------------" CLEAR << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;


    std::cout << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|     Running Additional Test    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

    std::cout << RED"-------------- Testing Default Construction -------------" CLEAR << std::endl;

    Array<int> test1;
    std::cout << "Size is: " << test1.size() << std::endl;
    try {
        std::cout << "Attempting to access first element:" << std::endl;
        test1[0];
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << RED"-------------- Testing Unsigned Int Constructor -------------" CLEAR << std::endl;

    Array<int> test2(5);
    for (int i = 0; i < 5; i++)
        test2[i] = i + 1;

    std::cout << "Size is: " << test2.size() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << test2[i] << std::endl;

    std::cout << std::endl;
    std::cout << RED"-------------- Testing Improper access -------------" CLEAR << std::endl;
    try {
        test2[25];
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << RED"-------------- Testing Copy Constructor & Copy Assigment Overload Deep Copy -------------" CLEAR << std::endl;
    Array<int> test3(test2);
    Array<int> test4;
    test4 = test2;

    for (int i = 0; i < 5; i++)
        test2[i] = 0;

    for (int i = 0; i < 5; i++) {
        std::cout << test3[i];
        std::cout << test4[i] << std::endl;
    }


    
}