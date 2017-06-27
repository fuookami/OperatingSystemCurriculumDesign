//
// Created by fuookami on 17-6-26.
//

#include "PCBuffer.h"
#include <string>
#include <iostream>

PCBuffer::PCBuffer()
	: buffer(std::deque<char>())
{
}

PCBuffer::~PCBuffer()
{
}

void PCBuffer::push(const char ch)
{
	if (this->isFull())
		throw std::out_of_range(std::string("Buffer is Full."));

	buffer.push_back(ch);
}

char PCBuffer::pop(void)
{
	if (this->isEmpty())
		throw std::out_of_range(std::string("Buffer is Empty."));

	char ele(buffer.front());
	buffer.pop_front();
	return std::move(ele);
};