#include "bsc.hpp"

static bool	open_files(std::ifstream& infile, std::ifstream& dataBase, const char* filename)
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

static void	insert_line(std::map<std::string, double>& infoMap, std::string& line)
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

static std::string	print_error(std::string& date)
{
	std::cerr << "Error: invalid date => " << date << std::endl;
	return "";
}

static bool isstrnumeric(const std::string& str)
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

static bool	check_date_validity(size_t year, size_t month, size_t day)
{
	if (year < 2009
		|| day < 1 || month < 1
		|| day > 31 || month > 12
		|| (year == 2009 && month == 1 && day == 1)
		|| ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
		|| (month == 2 && day > 29)
		|| (month == 2 && year % 4 != 0 && day > 28))
		return false;
	return true;
}

static std::string	manage_date(std::string& date)
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
	//std::cout << "Year: " << syear << " | Month: " << smonth << " | Day: " << sday << std::endl;
	//std::cout << "Year l: " << syear.length() << " | Month: " << smonth.length() << " | Day: " << sday.length() << std::endl;
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
	//std::cout << sday << std::endl;
	return date;
}

static void	find_info(std::map<std::string, double>& infoMap, std::string& line)
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
	num = line.substr(vbar + spaces, line.length() - date.length());
	if ((date = manage_date(date)) == "")
		return ;
	std::map<std::string, double>::iterator it = infoMap.begin();
	it++;

}

int	main (int argc, char* argv[])
{
	std::ifstream					infile;
	std::ifstream					dataBase;
	std::string						line;
	std::map<std::string, double>	infoMap;

	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	if (!open_files(infile, dataBase, argv[1]))
	{
		std::cerr << "Error: File not found" << std::endl;
		return 2;

	}
	std::getline(dataBase, line);
	while (std::getline(dataBase, line))
		insert_line(infoMap, line);
	std::getline(infile, line);
	while (std::getline(infile, line))
		find_info(infoMap, line);
	infile.close();
	dataBase.close();
}
