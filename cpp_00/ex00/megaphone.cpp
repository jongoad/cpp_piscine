#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE NOISE *";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int c = 0; c < strlen(argv[i]); c++)
				std::cout << toupper(argv[i][c]);
			if (argv[i + 1] != NULL)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
}





/*

$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>

- If no arguments passed, print feedback noise message with a newline
- Capitalize all alpha characters

*/