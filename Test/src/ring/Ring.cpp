//
// Created by fuookami on 17-6-27.
//

#include "Ring.h"
#include <iostream>
#include <sstream>
#include <random>

RingThread::RingThread(unsigned int threadId)
	: id(threadId), data(), sema(SafePthreadSema::create())
{
	if (id == 1)
		data.set(1);
}

RingThread::~RingThread()
{

}

void RingThread::start(RingThread *nextThread)
{
	std::ostringstream sout;
	sout << "Thread " << id << " start." << std::endl;
	printMsg(sout.str());
	pNextThread = nextThread;

	pthread_create(&tid, nullptr, run, (void *)this);
}

void RingThread::join()
{
	pthread_join(tid, nullptr);
}

void* RingThread::run(void *args)
{
	RingThread *pThisThread((RingThread *)args);

	if (pThisThread->id != 1)
		pThisThread->sema->wait();

	std::ostringstream sout1;
	sout1 << "Thread " << pThisThread->id << " send " << pThisThread->data.toInteger()
	     << " to Thread " << pThisThread->pNextThread->id << "." << std::endl;
	pThisThread->printMsg(sout1.str());

	pThisThread->pNextThread->receive(Data(pThisThread->data.toInteger() + 1));

	if (pThisThread->id == 1)
		pThisThread->sema->wait();

	std::ostringstream sout2;
	sout2 << "Thread " << pThisThread->id << " has been cloesd." << std::endl;
	pThisThread->printMsg(sout2.str());

	return nullptr;
}

void RingThread::receive(const Data &d)
{
	data = d;

	std::ostringstream sout;
	sout << "Thread " << id << ": get " << data.toInteger() << "." << std::endl;
	printMsg(sout.str());

	sema->signal();
}

void RingThread::printMsg(const std::string &str)
{
	std::cout << str;
}

Ring::Ring()
	: threadNum(0)
{
	std::random_device rd;
	threadNum = 10 + rd() % 10;
	std::cout << "Random thread num: " << threadNum << std::endl;

	for (unsigned long i(0); i != threadNum; ++i)
		threads.push_back(RingThread((unsigned int)i + 1));
}

Ring::~Ring()
{
}

Ring& Ring::getReference()
{
	static Ring ret;
	return ret;
}

void Ring::run()
{
	for (unsigned long i(0); i != threadNum; ++i)
	{
		unsigned long j((i + 1) % threadNum);
		threads[i].start(&threads[j]);
	}

	for (unsigned long i(0); i != threadNum; ++i)
		threads[i].join();

	std::cout << "All threads has been closed." << std::endl;
}