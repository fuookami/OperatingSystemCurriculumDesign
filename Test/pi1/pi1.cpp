//
// Created by fuookami on 17-6-24.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>

void *computePi(void *arg)
{
	double *ret = new double;

	bool positive(arg[1] % 4 == 1);
	for (unsigned long i(arg[1]), j(arg[0]); i != j; i -= 2)
	{
		ret += (positive ? 1 : -1) * i;
		positive = !positive;
	}

	return ret;
}


int main(int argc, char *argv[])
{


	double *rh();

	return 0;
}