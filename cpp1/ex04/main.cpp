#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>


std::string	getInfileContent(char *infile)
{
	std::string	result;
	std::string	line;
	
	std::ifstream readFile(infile);
	if (readFile.fail())
		return (result);
	while (std::getline(readFile, line))
	{
		result = result + line + "\n";
	}
	readFile.close();
	return (result);
}

int	replaceContent(std::string& infileContent, std::string str1, std::string str2)
{
	int	counter = 0;
	int index = 1;
	while (1)
	{
		index = infileContent.find(str1);
		if (index == -1)
			break;
		infileContent.erase(index, str1.size());
		infileContent.insert(index, str2);
		counter++;
	}
	if (counter == 0)
	{
		std::cout << "No occurence of '" << str1 << "' has been found." <<std::endl;
		return (1);
	}
	return (0);
}

void	fillOutfile(std::string infileContent, char *infile)
{
	std::string infileName = infile;
	std::string outfile = infileName + ".replace";

	std::ofstream writeEnd(outfile.c_str());
	if (writeEnd.fail())
	{
		std::cout << "Couldn't create or write in " << outfile << std::endl;
		return;
	}
	writeEnd << infileContent;

	writeEnd.close();
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Missing or extra arguments: you must enter a filename, a str1 and str2." << std::endl;
		return (0);
	}
	std::string	str1 = av[2];
	std::string	str2 = av[3];

	std::string infileContent = getInfileContent(av[1]);
	if (infileContent.empty())
	{
		std::cout << "Couldn't open or read " << av[1] << std::endl;
		return (1);
	}
	if (replaceContent(infileContent, str1, str2) == 1)
		return (1);
	fillOutfile(infileContent, av[1]);
	return(0);
}
