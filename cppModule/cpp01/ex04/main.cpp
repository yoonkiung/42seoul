#include <fstream>
#include <iostream>
#include <string>

int is_error(int ac)
{
	if (ac != 4)
		return (0);
	return (1);
}

void convert(std::string &content, std::string str1, std::string str2)
{
	std::string::size_type n = content.find(str1);

	while (n != std::string::npos)
	{
		content.erase(n, str1.length());
		content.insert(n, str2);
		n = content.find(str1 , n + str1.length() + 1);
	}
}

int main(int ac, char **av)
{
	if (!is_error(ac))
	{
		std::cout << "argument error" << std::endl;
		return (1);
	}
	
	std::string filename(av[1]);
	std::string str1(av[2]);
	std::string str2(av[3]);
	std::string content;
	
	std::ifstream in(filename);
	std::ofstream out(filename + ".replace");
	if (!in.is_open() || !out.is_open())
	{
		std::cout << "file open error" << std::endl;
		return (1);
	}
	in >> content;
	convert(content, str1, str2);
	out << content << std::endl;
}