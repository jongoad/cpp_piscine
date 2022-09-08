#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for(int i = 1; i < argc; i++) {
			for(size_t c = 0; c < strlen(argv[i]); c++)
				std::cout << (char)toupper(argv[i][c]);
		}
	}
	std::cout << std::endl;
}