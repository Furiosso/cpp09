#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <list>
# include <limits>
# include <ctime>

void				charge_deque_pairs(std::deque<unsigned int>& d, std::deque<std::pair<unsigned int, unsigned int> >& pairs);
int					check_validity(const std::string& num);
size_t				get_len(const char** args);
bool				isOdd(std::deque<unsigned int>&d, unsigned int& remanent);
void				mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& pairs);
int					parse_list(const char** args, std::vector<unsigned int>& v, std::deque<unsigned int>& d, std::list<unsigned int>& l);
int					print_error(const std::string& err, int err_key);
void				searchAndInsert(std::deque<unsigned int>& d, std::deque<std::pair<unsigned int, unsigned int> >& pairs);
void				sort_deque(std::deque<unsigned int>& d);
const std::string	trim(const std::string& num);

#endif
