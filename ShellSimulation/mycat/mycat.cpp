//
// Created by fuookami on 17-5-30.
//

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		std::cout << argv[1];
		return 3;
	}

	std::cout << fin.rdbuf();
	fin.close();
	return 0;
}