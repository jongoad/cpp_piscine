#include "../includes/Convert.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"




int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "No string entered" << std::endl;
	else {
		Convert Converter(argv[1]);
	}
	
	return (0);
}
