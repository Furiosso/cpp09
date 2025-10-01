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
