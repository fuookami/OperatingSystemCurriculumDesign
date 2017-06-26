//
// Created by fuookami on 17-6-26.
//

#include "PC2.h"

int main(void)
{
	PC2 &pc2(PC2::getReference());
	pc2.run();

	return 0;
}