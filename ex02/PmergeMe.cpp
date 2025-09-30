#include "PmergeMe.hpp"

int	print_error(const std::string& err, const int err_key)
{
	std::cerr << "Error: " << std::endl << err << std::endl;
	return err_key;
}

size_t	get_len(const char** args)
{
	size_t	len;

	len = 0;
	while (args[len])
		++len;
	return len;
}

int	check_validity(const std::string& num)
{
	size_t	i;
	size_t	len;
	size_t	num_len;

	i = 0;
	len = num.length();
	while (i < len && std::isspace(num[i]))
		i++;
	if (i == len)
		return print_error("empty value", 2);
	if (num[i] == '+')
		++i;
	num_len = 0;
	for (i = i; i < len; ++i)
	{
		if (std::isspace(num[i]))
			break ;
		if (!std::isdigit(num[i]))
			return print_error("invalid input", 3);
		++num_len;
		if (num_len > 10)
			return print_error("value too large", 4);
	}
	while (i < len && std::isspace(num[i]))
		i++;
	if (i != len)
		return print_error("invalid value", 5);
	return 0;
}

const std::string	trim(const std::string& num)
{
	size_t	start;
	size_t	finish;
	size_t	len;
	
	start = 0;
	while (std::isspace(num[start]))
		++start;
	len = num.length();
	finish = len;
	while (std::isspace(num[finish - 1]))
		--finish;
	if (start == 0 && finish == len)
		return num;
	return num.substr(start, finish);
}

bool	check_duplicity(std::vector<unsigned int>& v, const unsigned int num)
{
	for (std::vector<unsigned int>::iterator begin = v.begin(); begin < v.end(); ++begin)
	{
		if (num == *begin)
			return true;
	}
	return false;
}

int	parse_list(const char** args, std::vector<unsigned int>& v, std::deque<unsigned int>& d, std::list<unsigned int>& l)
{
	size_t			len;
	long long		lnum;
	unsigned int	num;

	len = get_len(args);
	for (size_t i = 0; i < len; ++i)
	{
		if (int err = check_validity(args[i]))
			return err;
		lnum = std::atoll(trim(args[i]).c_str());
		if (lnum > std::numeric_limits<unsigned int>::max())
			return print_error("value too large", 6);
		num = static_cast<int>(lnum);
		if (check_duplicity(v, num))
			return print_error("duplicated value", 7);
		v.push_back(num);
		d.push_back(num);
		l.push_back(num);
	}
	return 0;
}
