#include "PmergeMe.hpp"

static bool	check_duplicity(std::list<unsigned int>& l, const unsigned int num)
{
	for (std::list<unsigned int>::iterator begin = l.begin(); begin != l.end(); ++begin)
	{
		if (num == *begin)
			return true;
	}
	return false;
}

int	parse_list_l(const char** args, std::list<unsigned int>& l)
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
		if (check_duplicity(l, num))
			return print_error("duplicated value", 7);
		l.push_back(num);
	}
	return 0;
}
