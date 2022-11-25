#include <iostream>
#include <fstream>
#include <sstream>

/* Open input file and read to a string */
std::string inputFileToString(const std::string &path) {
	std::ifstream inputFile;
	std::ostringstream ss;

	inputFile.open(path);
	if (!inputFile.is_open()) {
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
	if (!outputFile.is_open()) {
		std::cerr << "Unable to open file - '" << std::string(path) + ".replace" << "'" << std::endl;
		exit(EXIT_FAILURE);
	}
	outputFile << output;
}

/* Find instances of findStr and replace with replaceStr */
std::string replaceStrings(std::string input, std::string findStr, std::string replaceStr) {
	size_t pos;

	while (1) {
		pos = input.find(findStr);				/* Find the first occurrence of first character in findStr */
		if (pos == std::string::npos)
			return (input);
		input.erase(pos, findStr.length()); 	/* Erase occurence of findStr */
		input.insert(pos, replaceStr); 			/* Insert replaceStr */
	}
	return (input);
}

int	main(int argc, char **argv)
{
	/* Check input parameters */
	if (argc != 4) {
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
