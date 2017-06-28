//
// Created by fuookami on 17-6-26.
//

#include "PC1.h"
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
		return Retcodes::ARG_NUM_ERROR;

	PC1 &pc1(PC1::getReference());
	pc1.run();

	return Retcodes::NO_ERROR;
}