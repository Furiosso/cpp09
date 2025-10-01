#include "PmergeMe.hpp"

bool	isOdd(std::deque<unsigned int>&d, unsigned int& remanent)
{
	if (d.size() % 2 != 0)
	{
		remanent = *d.begin();
		d.pop_front();
		return true;
	}
	return false;
}

void	charge_deque_pairs(std::deque<unsigned int>& d, std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
	for (std::deque<unsigned int>::iterator begin = d.begin(); begin < d.end(); begin += 2)
	{
		if (begin[0] < begin[1])
			pairs.push_back(std::make_pair(begin[0], begin[1]));
		else
			pairs.push_back(std::make_pair(begin[1], begin[0]));
	}
}

static std::deque<std::pair<unsigned int, unsigned int> >	mergeDeques(std::deque<std::pair<unsigned int, unsigned int> >& left, std::deque<std::pair<unsigned int, unsigned int> >& right)
{
	std::deque<std::pair<unsigned int, unsigned int> >	res;
	size_t												i;
	size_t												j;
	size_t												len[2];

	i = j = 0;
	len[0] = left.size();
	len[1] = right.size();
	while (i < len[0] && j < len[1])
	{
		if (left[i].second < right[j].second)
		{
			res.push_back(left[i]);
			++i;
		}
		else
		{
			res.push_back(right[j]);
			++j;
		}
	}
	while (i < len[0])
	{
		res.push_back(left[i]);
		++i;
	}
	while (j < len[1])
	{
		res.push_back(right[j]);
		++j;
	}
	return res;
}

void	mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
	size_t												middle;
	std::deque<std::pair<unsigned int, unsigned int> >	left;
	std::deque<std::pair<unsigned int, unsigned int> >	right;

	if (pairs.size() == 1)
		return ;
	middle = pairs.size() / 2;
	left.assign(pairs.begin(), pairs.begin() + middle);
	right.assign(pairs.begin() + middle, pairs.end());
	mergeSort(left);
	mergeSort(right);
	pairs = mergeDeques(left, right);
}

static void	createJacobsthall(std::deque<unsigned int>& jacobsthall, size_t len)
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
			std::cout << "len: " << len << std::endl;
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
		std::cout << "i: " << i << std::endl;
	}
}

void	searchAndInsert(std::deque<unsigned int>& d, std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::deque<unsigned int>	jacobsthall;
	size_t						len;

	len = pairs.size();
	createJacobsthall(jacobsthall, len - 1);
	for (size_t i = 0; i < jacobsthall.size(); ++i)
		std::cout << jacobsthall[i] << " ";
	std::cout << std::endl;
	d.begin()++;
}
