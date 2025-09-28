#include "btc.hpp"

void	insert_line(std::map<std::string, double>& infoMap, std::string& line)
{
	size_t		comma;
	std::string	date;
	std::string	num;

	if ((comma = line.find(',')) != std::string::npos)
	{
		date = line.substr(0, comma);
		num = line.substr(comma + 1, line.length());
		infoMap.insert(std::pair<std::string, double>(date, std::strtod(num.c_str(), NULL)));
	}
}

std::string	manage_date(std::string& date)
{
	std::string	syear;
	std::string	smonth;
	std::string	sday;
	size_t		hyphen[2];

	if (date.length() > 10)
		return print_error(date);
	if ((hyphen[0] = date.find('-')) == std::string::npos)
		return print_error(date);
	if ((hyphen[1] = date.rfind('-')) == hyphen[0])
		return print_error(date);
	syear = date.substr(0, hyphen[0]);
	smonth = date.substr(hyphen[0] + 1, hyphen[1] - hyphen[0] -1);
	sday = date.substr(hyphen[1] + 1, date.length());
	if (syear.length() != 4 || smonth.length() > 2 || smonth.length() < 1 || sday.length() > 2 || sday.length() < 1
		|| !isstrnumeric(syear) || !isstrnumeric(smonth) || !isstrnumeric(sday))
		return print_error(date);
	if (smonth.length() == 1 || sday.length() == 1)
	{
		if (smonth.length() == 1)
			smonth = "0" + smonth;
		if (sday.length() == 1)
			sday = "0" + sday;
		date = syear + "-" + smonth + "-" + sday;
	}
	if (!check_date_validity(atoi(syear.c_str()), atoi(smonth.c_str()), atoi(sday.c_str())))
		return print_error(date);
	return date;
}

void	calculate_rate(const std::string& date, const double num, const std::map<std::string, double>& infoMap)
{
	std::map<std::string, double>::const_iterator it;
	
	it = infoMap.lower_bound(date);
	if (it == infoMap.end() || it->first != date)
		it--;
	std::cout << date << " => " << num << " = " << format_record(num * it->second) << std::endl;
}

void	manage_num(const std::string& date, std::string& snum, const std::map<std::string, double>& infoMap)
{
	size_t	i;
	double	num;

	if (snum.length() == 0 || (!std::isdigit(snum[0]) && snum[0] != '-' && snum[0] != '+'))
		return print_error("invalid number");
	i = 1;
	while (i < snum.length() && std::isdigit(snum[i]))
		++i;
	if (i < snum.length() && snum[i] == '.')
		++i;
	if (snum[i - 1] == '.' && i == snum.length())
		return print_error("invalid number");
	while (i < snum.length() && std::isdigit(snum[i]))
		++i;
	if (i < snum.length())
		return print_error("invalid number");
	num = std::strtod(snum.c_str(), NULL);
	if (num < 0.0)
		return print_error("not a positive number");
	if (num > 1000.0)
		return print_error("too large a number");
	calculate_rate(date, num, infoMap);
}

void	find_info(const std::map<std::string, double>& infoMap, std::string& line)
{
	size_t		vbar;
	std::string	date;
	std::string	num;
	size_t		spaces;

	if ((vbar = line.find('|')) == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	spaces = 0;
	while (std::isspace(line[vbar - spaces - 1]))
		++spaces;
	date = line.substr(0, vbar - spaces);
	spaces = 0;
	while (std::isspace(line[vbar + spaces + 1]))
		++spaces;
	num = line.substr(vbar + spaces + 1, line.length() - date.length());
	if ((date = manage_date(date)) == "")
		return ;
	manage_num(date, num, infoMap);
}
