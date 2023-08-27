#include <iostream>
#include <fstream>

int copy(std::string fname, std::string s1, std::string s2, std::string str) {
	std::ofstream outfile(fname + ".replace");
	size_t	pos;
	size_t	len = s1.size();
	std::string tmp;

	if (outfile.fail())
		return (1);
	pos = str.find(s1);
	while (pos != std::string::npos)
	{
		str = str.substr(0, pos) + s2 + str.substr(pos + len);
		pos = str.find(s1);
	}
	outfile << str;
	outfile.close();
	return (0);
}

int main(int ac, char **av)
{
	std::ifstream infile;
	std::string tmp;
	std::string info;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (!infile)
	{
		std::cout << "No such file or directory : " << av[1] << std::endl;
		return (1);
	}

	while (std::getline(infile, tmp))
	{
		info += tmp;
		if (!infile.eof())
			info += '\n';
	}
	return (copy(av[1], av[2], av[3], info));
}
