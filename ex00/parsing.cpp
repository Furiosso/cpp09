#include "btc.hpp"

bool isstrnumeric(const std::string& str)
{
	size_t	len;

	len = str.length();
	for (size_t i = 0; i < len; ++i)
	{
		if (!isdigit(str[i]))
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
	if (line.substr(i, 4) != "date")
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
	if (i != len)
		return false;
	return true;
}

std::string&	trim_line(std::string& line)
{
	size_t	begin;
	size_t	finish;

	begin = 0;
	while (std::isspace(line[begin]))
		++begin;
	finish = line.length();
	while (std::isspace(line[finish - 1]))
		--finish;
	line = line.substr(begin, finish - begin);
	return line;	
}

const std::string	format_record(const double n)
{
	std::stringstream	ss;
	std::string			sn;
	size_t				len;
	size_t				i;

	ss << std::fixed << std::setprecision(2) << n;
	sn = ss.str();
	len = i = sn.length();
	while (sn[i - 1] == '0')
		--i;
	if (sn[i - 1] == '.')
		--i;
	if (i != len)
		sn = sn.substr(0, i);
	return sn;
}

bool	check_date_validity(const size_t year, const size_t month, const size_t day)
{
	if (year < 2009 || year > 2025
		|| day < 1 || month < 1
		|| day > 31 || month > 12
		|| (year == 2009 && month == 1 && day == 1)
		|| ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
		|| (month == 2 && day > 29)
		|| (month == 2 && year % 4 != 0 && day > 28))
		return false;
	return true;
}
