#include "PmergeMe.hpp"

bool	isOddL(std::list<unsigned int>& l, unsigned int& remanent)
{
	if (l.size() % 2 != 0)
	{
		remanent = *l.begin();
		l.pop_front();
		return true;
	}
	return false;
}

void	charge_list_pairs(std::list<unsigned int>& l, std::list<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::list<unsigned int>::iterator	next;
	for (std::list<unsigned int>::iterator begin = l.begin(); begin != l.end(); std::advance(begin, 2))
	{
		next = ++begin;
		--begin;
		if (*begin < *next)
			pairs.push_back(std::make_pair(*begin, *next));
		else
			pairs.push_back(std::make_pair(*next, *begin));
	}
}

static std::list<std::pair<unsigned int, unsigned int> >	mergeList(std::list<std::pair<unsigned int, unsigned int> >& left, std::list<std::pair<unsigned int, unsigned int> >& right)
{
	std::list<std::pair<unsigned int, unsigned int> >			res;
	std::list<std::pair<unsigned int, unsigned int> >::iterator	it[2];
	std::list<std::pair<unsigned int, unsigned int> >::iterator	end[2];

	it[0] = left.begin();
	it[1] = right.begin();
	end[0] = left.end();
	end[1] = right.end();
	while (it[0] != end[0] && it[1] != end[1])
	{
		if (it[0]->second < it[1]->second)
		{
			res.push_back(*it[0]);
			it[0] = ++it[0];
		}
		else
		{
			res.push_back(*it[1]);
			it[1] = ++it[1];
		}
	}
	while (it[0] != end[0])
	{
		res.push_back(*it[0]);
		it[0] = ++it[0];
	}
	while (it[1] != end[1])
	{
		res.push_back(*it[1]);
		it[1] = ++it[1];
	}
	return res;
}

void	mergeSortL(std::list<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::list<std::pair<unsigned int, unsigned int> >			left;
	std::list<std::pair<unsigned int, unsigned int> >			right;
	std::list<std::pair<unsigned int, unsigned int> >::iterator	middle;

	if (pairs.size() == 1)
		return ;
	middle = pairs.begin();
	std::advance(middle, pairs.size() / 2);
	left.assign(pairs.begin(), middle);
	right.assign(middle, pairs.end());
	mergeSortL(left);
	mergeSortL(right);
	pairs = mergeList(left, right);
}

static void	createJacobsthall(std::list<unsigned int>& jacobsthall, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 3;
	k = 1;
	while (i < len)
	{
		l = j;
		if (j - 1 >= len)
		{
			while (len > k - 1)
			{
				jacobsthall.push_back(len);
				--len;
			}
			return ;
		}
		while (j - 1 > k - 1)
		{
			jacobsthall.push_back(j - 1);
			--j;
		}
		j = l + k * 2;
		k = l;
		i = jacobsthall.size() - 1;
	}
}

void	searchAndInsertL(std::list<unsigned int>& l, std::list<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::list<unsigned int>										jacobsthall;
	size_t														len;
	std::list<unsigned int>::iterator							it;
	std::list<std::pair<unsigned int, unsigned int> >::iterator	needle;

	len = pairs.size();
	createJacobsthall(jacobsthall, len - 1);
	for (it = jacobsthall.begin(); it != jacobsthall.end(); ++it)
	{
		needle = pairs.begin();
		std::advance(needle, *it);
		l.insert(std::lower_bound(l.begin(), l.end(), needle->first), needle->first);
	}
}
