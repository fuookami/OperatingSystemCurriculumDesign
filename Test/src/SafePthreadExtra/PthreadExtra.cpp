//
// Created by fuookami on 17-6-25.
//

#include "PthreadExtra.h"

SafePthreadMutex::SafePthreadMutex(pthread_mutexattr_t *attr)
	: initSuccess(pthread_mutex_init(&mutex, attr) != 0)
{
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

pthread_mutex_t &SafePthreadMutex::get()
{
	return mutex;
}

pthread_mutex_t *SafePthreadMutex::getPtr()
{
	return &mutex;
}

bool SafePthreadMutex::lock()
{
	return pthread_mutex_lock(&mutex) == 0;
}

bool SafePthreadMutex::unlock()
{
	return pthread_mutex_unlock(&mutex) == 0;
}

bool SafePthreadMutex::success() const
{
	return initSuccess;
}

SafePthreadCond::SafePthreadCond(pthread_condattr_t *attr)
	: initSuccess(pthread_cond_init(&cond, attr) != 0)
{

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

pthread_cond_t& SafePthreadCond::get()
{
	return cond;
}

pthread_cond_t* SafePthreadCond::getPtr()
{
	return &cond;
}

bool SafePthreadCond::wait(pthread_mutex_t *pMutex)
{
	return pthread_cond_wait(&cond, pMutex) == 0;
}

bool SafePthreadCond::wait(SafePthreadMutex *pSafeMutex)
{
	return pthread_cond_wait(&cond, pSafeMutex->getPtr()) == 0;
}

bool SafePthreadCond::wait(std::shared_ptr<SafePthreadMutex> &spSafeMutex)
{
	return pthread_cond_wait(&cond, spSafeMutex->getPtr()) == 0;
}

bool SafePthreadCond::signal()
{
	return pthread_cond_signal(&cond) == 0;
}

bool SafePthreadCond::broadcast()
{
	return pthread_cond_broadcast(&cond) == 0;
}

bool SafePthreadCond::success() const
{
	return initSuccess;
}