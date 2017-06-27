//
// Created by fuookami on 17-6-26.
//

#pragma once

#include <deque>

class PCBuffer
{
 public:
  PCBuffer();
  ~PCBuffer();

  inline bool isEmpty(void) const;
  inline bool isFull(void) const;
  inline unsigned long size(void) const;
  static inline unsigned long capacity();

  void push(const char ch);
  char pop(void);

 private:
  static const unsigned long MaxBufferSize = 4;
  std::deque<char> buffer;
};

bool PCBuffer::isEmpty() const
{
	return buffer.empty();
}

bool PCBuffer::isFull() const
{
	return buffer.size() == MaxBufferSize;
}

unsigned long PCBuffer::size() const
{
	return buffer.size();
}

unsigned long PCBuffer::capacity()
{
	return MaxBufferSize;
}