#ifndef BSC_HPP
# define BSC_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <algorithm>
# include <cstdlib>
# include <iomanip>

std::string		print_error(const std::string& date);
void			print_error(const char* str);
bool			isallspaces(const std::string line);
bool			isemptyrecord(const std::string& line);
bool			isheader(const std::string& line);
std::string&	trim_line(std::string& line);

#endif