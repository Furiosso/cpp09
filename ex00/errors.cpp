#include "btc.hpp"

std::string	print_error(const std::string& date)
{
	std::cerr << "Error: ";
	if (date.length() == 0)
		std::cerr << "empty date";
	else
		std::cerr << "invalid date";
	std::cerr << std::endl;
	return "";
}

void	print_error(const char* str)
{
	std::cerr << "Error: "<< str << std::endl;
}

bool	open_files(std::ifstream& infile, std::ifstream& dataBase, const char* filename)
{
	infile.open(filename);
	if (!infile)
		return false;
	dataBase.open("data.csv");
	if (!dataBase)
	{
		infile.close();
		return false;
	}
	return true;
}
