#include "btc.hpp"

int	main (int argc, char* argv[])
{
	std::ifstream					infile;
	std::ifstream					dataBase;
	std::string						line;
	std::map<std::string, double>	infoMap;

	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	if (!open_files(infile, dataBase, argv[1]))
	{
		std::cerr << "Error: File not found" << std::endl;
		return 2;
	}
	std::getline(dataBase, line);
	while (std::getline(dataBase, line))
		insert_line(infoMap, line);
	while (std::getline(infile, line))
	{
		line = trim_line(line);
		if (line.length() == 0 || isheader(line))
			;
		else if (line.length() == 1 && line[0] == '|')
			std::cerr << "Error: empty record" << std::endl;
		else
			find_info(infoMap, line);
	}
	infile.close();
	dataBase.close();
}
