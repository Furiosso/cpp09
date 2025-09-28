#include "bsc.hpp"

std::string	print_error(const std::string& date)
{
	std::cerr << "Error: invalid date => " << date << std::endl;
	return "";
}

void	print_error(const char* str)
{
	std::cerr << "Error: "<< str << std::endl;
}

bool	isemptyrecord(const std::string& line)
{
	size_t	i;
	size_t	len;

	len = line.length();
	if (len == 0)
		return true;
	i = 0;
	while (i < len && std::isspace(line[i]))
		i++;
	if (line[i] == '|')
		i++;
	else
		return false;
	while (i < len && std::isspace(line[i]))
		i++;
	if (i == len)
		return true;
	return false;
}
