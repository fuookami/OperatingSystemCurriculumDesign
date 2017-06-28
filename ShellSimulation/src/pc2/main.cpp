//
// Created by fuookami on 17-6-26.
//

#include "PC2.h"
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
		return Retcodes::ARG_NUM_ERROR;

	PC2 &pc2(PC2::getReference());
	pc2.run();

	return Retcodes::NO_ERROR;
}