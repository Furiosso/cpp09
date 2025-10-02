#include "PmergeMe.hpp"

bool	isOddV(std::vector<unsigned int>&v, unsigned int& remanent)
{
	if (v.size() % 2 != 0)
	{
		remanent = v.back();
		v.pop_back();
		return true;
	}
	return false;
}

void	charge_vector_pairs(std::vector<unsigned int>& v, std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	for (std::vector<unsigned int>::iterator begin = v.begin(); begin < v.end(); begin += 2)
	{
		if (begin[0] < begin[1])
			pairs.push_back(std::make_pair(begin[0], begin[1]));
		else
			pairs.push_back(std::make_pair(begin[1], begin[0]));
	}
}

static std::vector<std::pair<unsigned int, unsigned int> >	mergeVector(std::vector<std::pair<unsigned int, unsigned int> >& left, std::vector<std::pair<unsigned int, unsigned int> >& right)
{
	std::vector<std::pair<unsigned int, unsigned int> >	res;
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

void	mergeSortV(std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	size_t												middle;
	std::vector<std::pair<unsigned int, unsigned int> >	left;
	std::vector<std::pair<unsigned int, unsigned int> >	right;

	if (pairs.size() == 1)
		return ;
	middle = pairs.size() / 2;
	left.assign(pairs.begin(), pairs.begin() + middle);
	right.assign(pairs.begin() + middle, pairs.end());
	mergeSortV(left);
	mergeSortV(right);
	pairs = mergeVector(left, right);
}

static void	createJacobsthall(std::vector<unsigned int>& jacobsthall, size_t len)
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

void	searchAndInsertV(std::vector<unsigned int>& v, std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::vector<unsigned int>			jacobsthall;
	size_t								len;
	std::vector<unsigned int>::iterator	pos;

	len = pairs.size();
	createJacobsthall(jacobsthall, len - 1);
	for (size_t i = 0; i < jacobsthall.size(); ++i)
	{
		pos = std::lower_bound(v.begin(), v.end(), pairs[jacobsthall[i]].first);
		v.insert(pos, pairs[jacobsthall[i]].first);
	}
}
