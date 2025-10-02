#include "PmergeMe.hpp"

int	main(const int argc, const char* argv[])
{
	std::vector<unsigned int>	v;
	std::list<unsigned int>		l;
	clock_t						start[2];
	clock_t						finish[2];
	double						lapse[2];

	if (argc < 3)
		return print_error("invalid number of arguments", 1);
	start[0] = clock();
	if (int err = parse_list_v(&argv[1], v))
		return err;
	std::cout << "Before:\t";
	for (std::vector<unsigned int>::iterator begin = v.begin(); begin < v.end(); ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
	sort_vector(v);
	finish[0] = clock();
	lapse[0] = static_cast<double>(finish[0] - start[0]) / CLOCKS_PER_SEC * 1e6;
	start[1] = clock();
	if (int err = parse_list_l(&argv[1], l))
		return err;
	sort_list(l);
	std::cout << "After:\t";
	for (std::list<unsigned int>::iterator begin = l.begin(); begin != l.end(); ++begin)
		std::cout << *begin << " ";
	std::cout << std::endl;
	finish[1] = clock();
	lapse[1] = static_cast<double>(finish[1] - start[1]) / CLOCKS_PER_SEC * 1e6;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << lapse[0] << " us" << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with std::list   : " << lapse[1] << " us" << std::endl;
}
