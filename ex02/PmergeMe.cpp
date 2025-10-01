#include "PmergeMe.hpp"

void	sort_deque(std::deque<unsigned int>& d)
{
	unsigned int										remanent;
	bool												isodd;
	std::deque<std::pair<unsigned int, unsigned int> >	pairs;

	remanent = 0;
	isodd = isOdd(d, remanent);
	charge_deque_pairs(d, pairs);
	mergeSort(pairs);
	for (size_t i = 0; i < pairs.size(); ++i)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	std::cout << "len: " << pairs.size() << std::endl;
	d.clear();
	d.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); ++i)
		d.push_back(pairs[i].second);
	std::cout << "len: " << pairs.size() << std::endl;
	searchAndInsert(d, pairs);
	if (isodd)
		std::cout << "fuck you\n";
}
