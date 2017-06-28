//
// Created by fuookami on 17-6-27.
//

#include "Ring.h"
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
		return Retcodes::ARG_NUM_ERROR;

	Ring &ring(Ring::getReference());
	ring.run();

	return Retcodes::NO_ERROR;
}