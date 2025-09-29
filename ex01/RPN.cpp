#include "RPN.hpp"

static bool	isoperand(const char c)
{
	if (c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/')
		return true;
	return false;
}

bool	are_arguments_correct(const std::string& args)
{
	size_t	len;

	len = args.length();
	for (size_t i = 0; i < len; ++i)
	{
		while (isspace(args[i]))
			++i;
		if ((!isdigit(args[i]) && !isoperand(args[i]))
			|| (i + 1 < len && !isspace(args[i + 1])))
			return false;
	}
	return true;
}

int	print_error_message(int i)
{
	std::cout << "Error" << std::endl;
	return i;
}

static unsigned int	execute_operation(const unsigned int x, const unsigned int y, const char operation)
{
	unsigned int	result;

	if (operation == '+')
		result = x + y;
	if (operation == '-')
		result = x - y;
	if (operation == '*')
		result = x * y;
	if (operation == '/')
		result = x / y;
	return result;
}

int	execute_calculation(const std::string& operation)
{
	std::stack<unsigned int>	s;
	unsigned int				x;
	unsigned int				y;

	for (size_t i = 0; i < operation.length(); ++i)
	{
		while (isspace(operation[i]))
			++i;
		if (isdigit(operation[i]))
			s.push(operation[i] - '0');
		if (isoperand(operation[i]))
		{
			if (s.size() == 0)
				return print_error_message(3);
			y = s.top();
			s.pop();
			if (s.size() == 0)
				return print_error_message(4);
			x = s.top();
			s.pop();
			s.push(execute_operation(x, y, operation[i]));
		}
	}
	if (s.size() != 1)
		return print_error_message(5);
	std::cout << s.top() << std::endl;
	return 0;
}
