//============================================================================
// Name        : MinCut.cpp
// Author      : Emmanuel Weber
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory.h>

using namespace std;

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cout << "Usage: MinCut filename" << endl;
		exit(0);
	}
	int mat[200][200];

	memset(mat,0,sizeof(mat));

	std::ifstream infile(argv[1]);

	std::string line;
	while (std::getline(infile, line))
	{
		cout << line << endl;
		std::istringstream iss(line);
		int entry;
		int index = -1;
		while (iss >> entry)
		{
			if(index < 0)
				index = entry;
			else
				mat[index][entry] = 1;
		}
	}
	return 0;
}
