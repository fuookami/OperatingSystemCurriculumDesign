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
	PC2 *p((PC2 *)args);
	for (char i('a'); i != 'i'; ++i)
	{
		p->buff1EmptySema->wait();
		p->buff1MutexSema->wait();

		p->printMsg(std::string("Produce: put ") +
			(char)i + std::string(" into buffer 1.\n"));
		p->buff1.push(i);

		p->buff1MutexSema->signal();
		p->buff1FullSema->signal();
	}

	p->printMsg(std::string("Producer has been closed.\n"));
	p->producerFinish = true;
	return nullptr;
}

void *PC2::calculator(void *args)
{
	PC2 *p((PC2 *)args);
	while (!p->producerFinish || !p->buff1.isEmpty())
	{
		p->buff1FullSema->wait();
		p->buff1MutexSema->wait();

		char i(p->buff1.pop());
		p->printMsg(std::string("Calculator: get ") +
			(char)i + std::string(" from buffer 1.\n"));

		p->buff1MutexSema->signal();
		p->buff1EmptySema->signal();

		p->buff2EmptySeam->wait();
		p->buff2MutexSema->wait();

		i = (char)toupper(i);
		p->printMsg(std::string("Calculator: put ") +
			(char)i + std::string(" into buffer 2.\n"));
		p->buff2.push(i);

		p->buff2MutexSema->signal();
		p->buff2FullSema->signal();
	}

	p->printMsg(std::string("Calculator has been closed.\n"));
	p->calculatorFinish = true;
	return nullptr;
}

void *PC2::customer(void *args)
{
	PC2 *p((PC2 *)args);
	while (!p->producerFinish || !p->buff2.isEmpty())
	{
		p->buff2FullSema->wait();
		p->buff2MutexSema->wait();

		char i(p->buff2.pop());
		p->printMsg(std::string("Customer: get ") +
			(char)i + std::string(" from buffer 2.\n"));

		p->buff2MutexSema->signal();
		p->buff2EmptySeam->signal();
	}

	p->printMsg(std::string("Customer has been closed.\n"));
	return nullptr;
}

void PC2::printMsg(const std::string &str)
{
	ioMutexSema->wait();
	std::cout << str;
	ioMutexSema->signal();
}