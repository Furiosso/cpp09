#include "PmergeMe.hpp"

int	main(const int argc, const char* argv[])
{
	std::vector<unsigned int>	v;
	std::deque<unsigned int>	d;
	std::list<unsigned int>		l;
	if (argc < 3)
		return print_error("invalid number of arguments", 1);
	if (int err = parse_list(&argv[1], v, d, l))
		return err;
	for (std::vector<unsigned int>::iterator begin = v.begin(); begin < v.end(); ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
}