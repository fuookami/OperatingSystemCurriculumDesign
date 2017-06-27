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
	void *args[2] = {this, nextThread};

	std::ostringstream sout;
	sout << "Thread " << id << " start." << std::endl;
	printMsg(sout.str());

	pthread_create(&tid, nullptr, run, args);
}

void RingThread::join()
{
	pthread_join(tid, nullptr);
}

void* RingThread::run(void *args)
{
	RingThread *pThisThread(((RingThread **)args)[0]);
	RingThread *pNextThread(((RingThread **)args)[1]);

	if (pThisThread->id != 1)
		pThisThread->sema->wait();

	pNextThread->receive(Data(pThisThread->data.toInteger() + 1));

	if (pThisThread->id == 1)
		pThisThread->sema->wait();

	std::ostringstream sout;
	sout << "Thread " << pThisThread->id << " has been cloesd." << std::endl;
	pThisThread->printMsg(sout.str());

	return nullptr;
}

void RingThread::receive(const Data &d)
{
	data = d;

	std::ostringstream sout;
	sout << "Thread " << id << ": get " << data.toInteger() << ".\n" << std::endl;
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
	threadNum = rd() % 20;
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

	std::cout << "All threads has been closed.\n" << std::endl;
}