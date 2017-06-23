//
// Created by fuookami on 17-6-24.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>

void *computePi(void *arg)
{
	double *ret = new double;

	unsigned long *args = (unsigned long *)arg;
	bool positive(args[1] % 4 == 1);
	for (unsigned long i(args[1]), j(args[0] - 2); i != j; i -= 2)
	{
		*ret += (positive ? 1 : -1) * 1.0 / i;
		std::cout << *ret << std::endl;
		positive = !positive;
	}

	return ret;
}


int main(int argc, char *argv[])
{
	unsigned long num[2] = {1, 9999};
	double *rh((double *)computePi((void *)num));

	std::cout << *rh * 4;
	return 0;
}