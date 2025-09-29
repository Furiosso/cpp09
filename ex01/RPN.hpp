#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <stack>

bool	are_arguments_correct(const std::string& args);
int		execute_calculation(const std::string& operation);
int		print_error_message(int i);

#endif
