#include "PmergeMe.hpp"

void	sort_vector(std::vector<unsigned int>& v)
{
	unsigned int										remanent;
	bool												isodd;
	std::vector<std::pair<unsigned int, unsigned int> >	pairs;

	remanent = 0;
	isodd = isOddV(v, remanent);
	charge_vector_pairs(v, pairs);
	mergeSortV(pairs);
	v.clear();
	v.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); ++i)
		v.push_back(pairs[i].second);
	searchAndInsertV(v, pairs);
	if (isodd)
		v.insert(std::lower_bound(v.begin(), v.end(), remanent), remanent);
}

void	sort_list(std::list<unsigned int>& l)
{
	unsigned int										remanent;
	bool												isodd;
	std::list<std::pair<unsigned int, unsigned int> >	pairs;

	remanent = 0;
	isodd = isOddL(l, remanent);
	charge_list_pairs(l, pairs);
	mergeSortL(pairs);
	l.clear();
	l.push_back(pairs.begin()->first);
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator i = pairs.begin(); i != pairs.end(); ++i)
		l.push_back(i->second);
	searchAndInsertL(l, pairs);
	if (isodd)
		l.insert(std::lower_bound(l.begin(), l.end(), remanent), remanent);
}
