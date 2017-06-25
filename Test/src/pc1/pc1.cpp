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