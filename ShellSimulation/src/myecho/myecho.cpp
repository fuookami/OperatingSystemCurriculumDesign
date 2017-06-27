//
// Created by fuookami on 17-5-30.
//

#include <iostream>

int main(int argc, char *argv[])
{
	for (int i(1); i < argc; ++i)
	{
		std::cout << argv[i];
	}

	return 0;
}