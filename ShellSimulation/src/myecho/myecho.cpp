//
// Created by fuookami on 17-5-30.
//

#include <iostream>
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
		return Retcodes::ARG_NUM_ERROR;

	for (int i(1); i < argc; ++i)
		std::cout << argv[i];

	return Retcodes::NO_ERROR;
}