//
// Created by fuookami on 17-6-25.
//

#include "SafePthreadExtra.h"

SafePthreadMutex::SafePthreadMutex(pthread_mutexattr_t *attr)
{
	initSuccess = pthread_mutex_init(&mutex, attr) == 0;
}

SafePthreadMutex::~SafePthreadMutex()
{
	if (initSuccess)
		pthread_mutex_destroy(&mutex);
}

std::shared_ptr<SafePthreadMutex> SafePthreadMutex::create(pthread_mutexattr_t *attr)
{
	std::shared_ptr<SafePthreadMutex> sp(new SafePthreadMutex(attr));

	return sp->success() ? sp : nullptr;
}

SafePthreadCond::SafePthreadCond(pthread_condattr_t *attr)
{
	initSuccess = pthread_cond_init(&cond, attr) == 0;
}

SafePthreadCond::~SafePthreadCond()
{
	if (initSuccess)
		pthread_cond_destroy(&cond);
}

std::shared_ptr<SafePthreadCond> SafePthreadCond::create(pthread_condattr_t *attr)
{
	std::shared_ptr<SafePthreadCond> sp(new SafePthreadCond(attr));

	return sp->success() ? sp : nullptr;
}