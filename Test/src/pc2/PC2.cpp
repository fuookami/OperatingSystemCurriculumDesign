//
// Created by fuookami on 17-6-26.
//

#include "PC2.h"
#include <iostream>

PC2::PC2()
	: buff1MutexSema(SafePthreadSema::createMutexTemplate()), buff2MutexSema(SafePthreadSema::createMutexTemplate()),
      ioMutexSema(SafePthreadSema::createMutexTemplate()),
      buff1EmptySema(SafePthreadSema::create()), buff1FullSema(SafePthreadSema::create()),
      buff2EmptySeam(SafePthreadSema::create()), buff2FullSema(SafePthreadSema::create()),
      buff1(), buff2(), producerFinish(false), calculatorFinish(false)
{
}

PC2::~PC2()
{
}

PC2 &PC2::getReference()
{
	static PC2 ret;
	return ret;
}

void PC2::run()
{
	pthread_create(&producerTid, nullptr, producer, (void *)this);
	pthread_create(&calculatorTid, nullptr, calculator, (void *)this);
	pthread_create(&customerTid, nullptr, customer, (void *)this);

	pthread_join(producerTid, nullptr);
	pthread_join(calculatorTid, nullptr);
	pthread_join(customerTid, nullptr);

	std::cout << "All thread has been closed." << std::endl;
}

void *PC2::producer(void *args)
{
	// todo
}

void *PC2::calculator(void *args)
{
	// todo
}

void *PC2::customer(void *args)
{
	// todo
}

void PC2::printMsg(const std::string &str)
{
	ioMutexSema->wait();
	std::cout << str;
	ioMutexSema->signal();
}