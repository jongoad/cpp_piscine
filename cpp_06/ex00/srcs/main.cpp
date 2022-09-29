#include "../includes/Convert.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw Convert::InvalidInput();
		Convert converter(argv[1]);
		std::cout << converter;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}