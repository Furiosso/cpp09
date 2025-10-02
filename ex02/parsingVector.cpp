#include "PmergeMe.hpp"

static bool	check_duplicity(std::vector<unsigned int>& v, const unsigned int num)
{
	for (std::vector<unsigned int>::iterator begin = v.begin(); begin < v.end(); ++begin)
	{
		if (num == *begin)
			return true;
	}
	return false;
}

int	parse_list_v(const char** args, std::vector<unsigned int>& v)
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
	}
	return 0;
}
