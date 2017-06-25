//
// Created by fuookami on 17-6-25.
//

#include "pc1.h"
#include <exception>

PC1Buff::PC1Buff()
	: buffer(std::deque<char>())
{
}

PC1Buff::~PC1Buff()
{
}

bool PC1Buff::isEmpty() const
{
	return buffer.empty();
}

bool PC1Buff::isFull() const
{
	return buffer.size() == MaxBufferSize;
}

unsigned long PC1Buff::size() const
{
	return buffer.size();
}

void PC1Buff::push(const char ch)
{
	if (this->isFull())
		throw std::out_of_range(std::string("Buffer is Full."));

	buffer.push_back(ch);
}

char PC1Buff::pop(void)
{
	if (this->isEmpty())
		throw std::out_of_range(std::string("Buffer is Empty."));

	char ele(buffer.front());
	buffer.pop_front();
	return std::move(ele);
};

PC1::PC1()
	: buff1Mutex(SafePthreadMutex::create()),
      buff2Mutex(SafePthreadMutex::create()),
      waitBuff1Full(SafePthreadCond::create()),
      waitBuff1Empty(SafePthreadCond::create()),
      waitBuff2Full(SafePthreadCond::create()),
      waitBuff2Empty(SafePthreadCond::create()),
      buff1(), buff2(), finish(false)
{
}

PC1::~PC1()
{
}

void PC1::run()
{
	pthread_create(&producerTid, nullptr, producer, nullptr);
	pthread_create(&calculatorTid, nullptr, calculator, nullptr);
	pthread_create(&customerTid, nullptr, customer, nullptr);

	pthread_join(producerTid, nullptr);
	pthread_join(calculatorTid, nullptr);
	pthread_join(customerTid, nullptr);

	std::cout << "All thread has been closed." << std::endl;
}

void *PC1::producer(void *args)
{
	for (char i('a'); i != 'i'; ++i)
	{
		buff1Mutex->lock();

		while(buff1.isFull())
			waitBuff1Empty->wait(buff1Mutex);

		std::cout << "Produce: put " << i << " into buffer 1." <<std::endl;
		buff1.push(i);

		waitBuff1Full->signal();
		buff1Mutex->unlock();
	}

	std::cout << "Producer has been closed." << std::endl;
	finish = true;
	return nullptr;
}

void *PC1::calculator(void *args)
{
	while (!finish || !buff1.isEmpty())
	{

	}

	std::cout << "Calculator has been closed." << std::endl;
	return nullptr;
}

void *PC1::customer(void *args)
{
	while (!finish || !buff2.isEmpty())
	{

	}

	std::cout << "Customer has been closed." << std::endl;
	return nullptr;
}