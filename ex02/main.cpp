#include "PmergeMe.hpp"

int	main(const int argc, const char* argv[])
{
	std::vector<unsigned int>	v;
	std::deque<unsigned int>	d;
	std::list<unsigned int>		l;
	//clock_t						start[2];
	//clock_t						finish[2];
	//double						lapse[2];

	if (argc < 3)
		return print_error("invalid number of arguments", 1);
	if (int err = parse_list(&argv[1], v, d, l))
		return err;
	std::cout << "Before:\t";
	for (std::deque<unsigned int>::iterator begin = d.begin(); begin < d.end(); ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
	//start[0] = clock();
	sort_deque(d);
	std::cout << "After:\t";
	for (std::deque<unsigned int>::iterator begin = d.begin(); begin < d.end(); ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
	//finish[0] = clock();
	//lapse[0] = static_cast<double>(finish[0] - start[0]) / CLOCKS_PER_SEC * 1e6;
}
