#include <iostream>
#include <fstream>
#include <sstream>

/* Open input file and read to a string */
std::string inputFileToString(const std::string &path) {
	std::ifstream inputFile;
	std::ostringstream ss;

	inputFile.open(path);
	if (!inputFile.is_open())
	{
		std::cerr << "Unable to open file - '" << path << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	ss << inputFile.rdbuf();
	return (ss.str());
}

/* Open output file and write string to file */
void	outputStringToFile(const std::string &path, std::string output) {
	std::ofstream outputFile;
	outputFile.open(std::string(path) + ".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Unable to open file - '" << std::string(path) + ".replace" << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	outputFile << output;
}

/* Find instances of findStr and replace with replaceStr */
std::string replaceStrings(std::string input, std::string findStr, std::string replaceStr) {
	size_t pos;

	//while (pos != std::string::npos)
	while (1)
	{
		pos = input.find(findStr); /* Find the first occurrence of first character in findStr */
		if (pos == std::string::npos)
			return (input);
		input.erase(pos, findStr.length()); 	/* Erase occurence of findStr */
		input.insert(pos, replaceStr); 						/* Insert replaceStr */
	}
	return (input);
}

int	main(int argc, char **argv)
{
	/* Check input parameters */
	if (argc != 4)
	{
		std::cerr << "Invalid command line arguments." << std::endl;
		std::cerr << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
		return (1);
	}
	/* Open file and read contents to string */
	std::string input = inputFileToString(argv[1]);

	if (std::string(argv[2]).length() != 0)
		input = replaceStrings(input, std::string(argv[2]), std::string(argv[3])); /* Attempt to replace strings */

	/* Write result to output file */
	outputStringToFile(argv[1], input);

	return (0);
}



/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.

Testing:
- What happens if either of the find or replace strings are empty
*/