//
// Created by fuookami on 17-6-24.
//

#pragma once

#include <array>
#include <algorithm>

namespace MultiThreadSort
{
	template <class RandomIt>
	void sort(RandomIt first, RandomIt last);

	namespace SubFun
	{
		template <class RandomIt>
		void *childThreadSort(void *args);

		template <class RandomIt>
		void selectionSort(RandomIt first, RandomIt last);
	}
}

namespace MultiThreadSort
{
	template <class RandomIt>
	void sort(RandomIt first, RandomIt last)
	{
		RandomIt middle(first + (last - first) / 2);

		pthread_t tid;
		std::array<RandomIt, 2> childThreadArgs = {middle, last};
		pthread_create(&tid, nullptr, SubFun::childThreadSort<RandomIt>, (void *)&childThreadArgs[0]);
		SubFun::selectionSort(first, middle);
		pthread_join(tid, nullptr);

		std::inplace_merge(first, middle, last);
	}

	namespace SubFun
	{
		template <class RandomIt>
		void *childThreadSort(void *args)
		{
			RandomIt *arg = (RandomIt *)args;
			RandomIt first(arg[0]), last(arg[1]);
			selectionSort(first, last);

			return nullptr;
		}

		template <class RandomIt>
		void selectionSort(RandomIt first, RandomIt last)
		{
			while (first != last)
			{
				RandomIt maxEleIt(first);
				for (RandomIt currIt(first + 1); currIt != last; ++currIt)
				{
					if (*currIt > *maxEleIt)
						maxEleIt = currIt;
				}
				std::swap(*first, *maxEleIt);

				++first;
			}
		}
	}
}