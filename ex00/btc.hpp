#ifndef BTC_HPP
# define BTC_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <algorithm>
# include <cstdlib>
# include <iomanip>
# include <sstream>

void				calculate_rate(const std::string& date, const double num, const std::map<std::string, double>& infoMap);
bool				check_date_validity(const size_t year, const size_t month, const size_t day);
void				find_info(const std::map<std::string, double>& infoMap, std::string& line);
const std::string	format_record(const double n);
void				insert_line(std::map<std::string, double>& infoMap, std::string& line);
bool				isheader(const std::string& line);
bool 				isstrnumeric(const std::string& str);
std::string			print_error(const std::string& date);
void				print_error(const char* str);
void				manage_num(const std::string& date, std::string& snum, const std::map<std::string, double>& infoMap);
std::string			manage_date(std::string& date);
bool				open_files(std::ifstream& infile, std::ifstream& dataBase, const char* filename);
std::string&		trim_line(std::string& line);

#endif