//
// Created by fuookami on 17-6-26.
//

#include "pc1.h"

int main(void)
{
	PC1 &pc1(PC1::getReference());
	pc1.run();

	return 0;
}