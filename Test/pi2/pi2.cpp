//
// Created by fuookami on 17-6-24.
//

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <pthread.h>

double calPiWithMultiThread(const unsigned long ed = 9999999, const unsigned int threadNum = 8);
void *computePi(void *arg);

int main(int argc, char *argv[])
{
	double pi(0.0);
	if (argc == 1)
		pi = calPiWithMultiThread();
	else if (argc == 2)
		pi = calPiWithMultiThread(std::stoul(argv[1]));
	else
		pi = calPiWithMultiThread(std::stoul(argv[1]), (unsigned int)std::stol(argv[2]));

	std::cout << pi << std::endl;
	return 0;
}

double calPiWithMultiThread(const unsigned long ed, const unsigned int threadNum)
{
	std::vector<pthread_t> tids;
	std::vector<void *> rets(threadNum, nullptr);
	std::vector<unsigned long> nums;

	nums.push_back(0);
	for (unsigned int i(0); i != threadNum; ++i)
	{
		unsigned long thisNum((ed * (i + 1)) / threadNum);
		if (thisNum % 2 == 0)
			++thisNum;
		nums.push_back(thisNum);
	}

	for (unsigned int i(0); i != threadNum; ++i)
	{
		tids.push_back(pthread_t());
		pthread_create(&tids[i], nullptr, &computePi, &nums[i]);
	}

	for (unsigned int i(0); i != threadNum; ++i)
		pthread_join(tids[i], &rets[i]);

	double ret(0.0);
	for (unsigned int i(0); i != threadNum; ++i)
	{
		ret += *(double *)rets[i];
		delete rets[i];
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