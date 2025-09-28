#include "bsc.hpp"

bool	isallspaces(const std::string line)
{
	for (size_t i = 0; i < line.length(); ++i)
	{
		if (!std::isspace(line[i]))
			return false;
	}
	return true;
}

bool	isheader(const std::string& line)
{
	size_t	i;
	size_t	len;
	
	len = line.length();
	if (len < 10)
		return false;
	i = 0;
	while (i < len && std::isspace(line[i]))
		i++;
	if (len - i < 4 || line.substr(i, 4) != "date")
		return false;
	i += 4;
	while (i < len && std::isspace(line[i]))
		i++;
	if (i == len || line[i] != '|')
		return false;
	i++;
	while (i < len && std::isspace(line[i]))
		i++;
	if (len - i < 5 || line.substr(i, 5) != "value")
		return false;
	i += 5;
	while (i < len && std::isspace(line[i]))
		i++;
	if (i != len)
		return false;
	return true;
}

std::string&	trim_line(std::string& line)
{
	size_t		i;

	i = 0;
	while (std::isspace(line[i]))
		++i;
	if (i)
		line = line.substr(i);
	i = 0;
	while (std::isspace(line[line.length() - 1 - i]))
		++i;
	if (i)
		line = line.substr(0, line.length() - i);
	return line;	
}
