#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	if (!are_arguments_correct(argv[1]))
		return print_error_message(2);
	return execute_calculation(argv[1]);
}