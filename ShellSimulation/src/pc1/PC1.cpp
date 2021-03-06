//
// Created by fuookami on 17-6-25.
//

#include "PC1.h"
#include <iostream>

PC1::PC1()
	: buff1Mutex(SafePthreadMutex::create()),
      buff2Mutex(SafePthreadMutex::create()),
      waitBuff1Full(SafePthreadCond::create()),
      waitBuff1Empty(SafePthreadCond::create()),
      waitBuff2Full(SafePthreadCond::create()),
      waitBuff2Empty(SafePthreadCond::create()),
      buff1(), buff2(),
      producerFinish(false), calculatorFinish(false)
{
}

PC1::~PC1()
{
}

PC1 &PC1::getReference()
{
	static PC1 ret;
	return ret;
}

void PC1::run() {
	pthread_create(&producerTid, nullptr, producer, (void *)this);
	pthread_create(&calculatorTid, nullptr, calculator, (void *)this);
	pthread_create(&customerTid, nullptr, customer, (void *)this);

	pthread_join(producerTid, nullptr);
	pthread_join(calculatorTid, nullptr);
	pthread_join(customerTid, nullptr);

	std::cout << "All threads have been closed." << std::endl;
}

void *PC1::producer(void *args)
{
	PC1 *p((PC1 *)args);
	for (char i('a'); i != 'i'; ++i)
	{
		p->buff1Mutex->lock();

		while (p->buff1.isFull())
			p->waitBuff1Empty->wait(p->buff1Mutex);

		p->buff1.push(i);

		if (i + 1 == 'i')
			p->producerFinish = true;

		p->waitBuff1Full->signal();
		p->buff1Mutex->unlock();

		p->printMsg(std::string("Produce: put ") +
			(char)i + std::string(" into buffer 1.\n"));
	}

	p->printMsg(std::string("Producer has been closed.\n"));
	return nullptr;
}

void *PC1::calculator(void *args)
{
	PC1 *p((PC1 *)args);
	while (!p->producerFinish || !p->buff1.isEmpty())
	{
		p->buff1Mutex->lock();

		while (p->buff1.isEmpty())
			p->waitBuff1Full->wait(p->buff1Mutex);

		char i(p->buff1.pop());

		p->waitBuff1Empty->signal();
		p->buff1Mutex->unlock();

		p->printMsg(std::string("Calculator: get ") +
			(char)i + std::string(" from buffer 1.\n"));

		p->buff2Mutex->lock();

		while (p->buff2.isFull())
			p->waitBuff2Empty->wait(p->buff2Mutex);

		i = (char)toupper(i);
		p->buff2.push(i);

		if (p->producerFinish && p->buff1.isEmpty())
			p->calculatorFinish = true;

		p->waitBuff2Full->signal();
		p->buff2Mutex->unlock();

		p->printMsg(std::string("Calculator: put ") +
			(char)i + std::string(" into buffer 2.\n"));
	}

	p->printMsg(std::string("Calculator has been closed.\n"));
	return nullptr;
}

void *PC1::customer(void *args)
{
	PC1 *p((PC1 *)args);
	while (!p->calculatorFinish || !p->buff2.isEmpty())
	{
		p->buff2Mutex->lock();

		while (p->buff2.isEmpty())
			p->waitBuff2Full->wait(p->buff2Mutex);

		char i(p->buff2.pop());

		p->waitBuff2Empty->signal();
		p->buff2Mutex->unlock();

		p->printMsg(std::string("Customer: get ") +
			(char)i + std::string(" from buffer 2.\n"));
	}

	p->printMsg(std::string("Customer has been closed.\n"));
	return nullptr;
}

void PC1::printMsg(const std::string &str)
{
	std::cout << str;
}
