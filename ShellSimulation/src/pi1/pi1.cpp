//
// Created by fuookami on 17-6-24.
//

#include <iostream>
#include <array>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "RetCodes.h"

double calPi(const std::array<unsigned long, 3> &nums);
void *computePi(void *arg);

int main(int argc, char *argv[])
{
	if (argc > 2)
		return Retcodes::ARG_NUM_ERROR;

	std::array<unsigned long, 3> nums = {1, 0, 0};
	if (argc == 1)
		nums[2] = 9999999;
	else
		nums[2] = std::stoul(std::string(argv[1]));

	nums[1] = nums[2] / 2;
	if (nums[1] % 2 == 0)
		nums[1] += 1;

	std::cout << calPi(nums);

	return Retcodes::NO_ERROR;
}

double calPi(const std::array<unsigned long, 3> &nums)
{
	pthread_t tid;
	void *ret1(nullptr), *ret2(nullptr);
	pthread_create(&tid, NULL, &computePi, (void *)(&nums[1]));
	ret1 = computePi((void *)(&nums.front()));
	pthread_join(tid, &ret2);

	double ret(*(double *)ret1 + *(double *)ret2);
	delete (double *)ret1;
	delete (double *)ret2;

	return ret * 4;
}

void *computePi(void *arg)
{
	double *ret = new double;

	unsigned long *args = (unsigned long *)arg;
	bool positive(args[1] % 4 == 1);
	for (unsigned long i(args[1]), j(args[0] - 2); i != j; i -= 2)
	{
		*ret += (positive ? 1 : -1) * 1.0 / i;
		positive = !positive;
	}

	return ret;
}