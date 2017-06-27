//
// Created by fuookami on 17-6-27.
//

#include "Ring.h"

int main(void)
{
	Ring &ring(Ring::getReference());
	ring.run();

	return 0;
}