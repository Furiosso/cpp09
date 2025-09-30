#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <list>
# include <limits>

int	parse_list(const char** args, std::vector<unsigned int>& v, std::deque<unsigned int>& d, std::list<unsigned int>& l);
int	print_error(const std::string& err, int err_key);

#endif
