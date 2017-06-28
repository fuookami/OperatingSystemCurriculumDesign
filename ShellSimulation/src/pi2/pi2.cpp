//
// Created by fuookami on 17-6-24.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "RetCodes.h"

double calPiWithMultiThread(const unsigned long ed = 9999999, const unsigned int threadNum = 8);
void *computePi(void *arg);

int main(int argc, char *argv[])
{
	if (argc > 3)
		return Retcodes::ARG_NUM_ERROR;

	double pi(0.0);
	if (argc == 1)
		pi = calPiWithMultiThread();
	else if (argc == 2)
		pi = calPiWithMultiThread(std::stoul(argv[1]));
	else
		pi = calPiWithMultiThread(std::stoul(argv[1]), (unsigned int)std::stol(argv[2]));

	std::cout << pi << std::endl;

	return Retcodes::NO_ERROR;
}

double calPiWithMultiThread(const unsigned long ed, const unsigned int threadNum)
{
	std::vector<pthread_t> tids;
	std::vector<void *> rets(threadNum, nullptr);
	std::vector<std::array<unsigned long, 2>> argvs;

	unsigned long lastNum(1);
	for (unsigned int i(0); i != threadNum; ++i)
	{
		unsigned long thisNum((ed * (i + 1)) / threadNum);
		if (thisNum % 2 == 0)
			++thisNum;

		argvs.push_back({lastNum, thisNum});
		lastNum = thisNum;
	}

	for (unsigned int i(0); i != threadNum; ++i)
	{
		tids.push_back(pthread_t());
		pthread_create(&tids[i], nullptr, &computePi, &argvs[i][0]);
	}

	for (unsigned int i(0); i != threadNum; ++i)
		pthread_join(tids[i], &rets[i]);

	double ret(0.0);
	for (unsigned int i(0); i != threadNum; ++i)
	{
		ret += *(double *)rets[i];
		delete (double *)rets[i];
	}

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