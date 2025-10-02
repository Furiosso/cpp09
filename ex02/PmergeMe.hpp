#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <limits>
# include <ctime>

void				charge_vector_pairs(std::vector<unsigned int>& d, std::vector<std::pair<unsigned int, unsigned int> >& pairs);
void				charge_list_pairs(std::list<unsigned int>& l, std::list<std::pair<unsigned int, unsigned int> >& pairs);
int					check_validity(const std::string& num);
size_t				get_len(const char** args);
bool				isOddL(std::list<unsigned int>& l, unsigned int& remanent);
bool				isOddV(std::vector<unsigned int>&d, unsigned int& remanent);
void				mergeSortV(std::vector<std::pair<unsigned int, unsigned int> >& pairs);
void				mergeSortL(std::list<std::pair<unsigned int, unsigned int> >& pairs);
int					parse_list_l(const char** args, std::list<unsigned int>& l);
int					parse_list_v(const char** args, std::vector<unsigned int>& v);
int					print_error(const std::string& err, int err_key);
void				searchAndInsertL(std::list<unsigned int>& l, std::list<std::pair<unsigned int, unsigned int> >& pairs);
void				searchAndInsertV(std::vector<unsigned int>& d, std::vector<std::pair<unsigned int, unsigned int> >& pairs);
void				sort_list(std::list<unsigned int>& l);
void				sort_vector(std::vector<unsigned int>& d);
const std::string	trim(const std::string& num);

#endif
