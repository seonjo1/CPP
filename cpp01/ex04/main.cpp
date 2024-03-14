#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "number of arguments is not three\n";
		return (1);
	}
	std::string filename(argv[1]);
	std::string filename_replace = filename + ".replace";
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	std::ifstream fin;
	std::ofstream fout;

	fout.open(filename_replace);
	if (fout.is_open())
	{
		fin.open(filename);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				std::string line;
				std::getline(fin, line);
				for (int i = 0; i < static_cast<int>(line.length()); i++)
				{
					if (line[i] == s1[0])
					{
						std::string substr = line.substr(i, s1.length());
						if (s1.compare(substr) == 0)
						{
							line = line.substr(0, i) + s2 + line.substr(i + s1.length());
							i = i + s2.length();
						}
					}
				}
				fout << line;
				if (!fin.eof())
					fout << "\n";
			}
			fin.close();
		}
		fout.close();
	}
	return (0);
}