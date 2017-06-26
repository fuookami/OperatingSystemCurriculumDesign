//
// Created by fuookami on 17-6-25.
//

#pragma once
#include <iostream>
#include <deque>
#include "../../include/SafePthreadExtra.h"

class PC1Buff
{
 public:
  PC1Buff();
  ~PC1Buff();

  inline bool isEmpty(void) const;
  inline bool isFull(void) const;
  inline unsigned long size(void) const;

  void push(const char ch);
  char pop(void);

 private:
  static const unsigned long MaxBufferSize = 4;
  std::deque<char> buffer;
};

class PC1
{
 public:
  ~PC1();

  static PC1 &getReference();
  void run();

 private:
  PC1(void);

  static void *producer(void *args);
  static void *calculator(void *args);
  static void *customer(void *args);

  void printMsg(const std::string &msg);

 private:
  pthread_t producerTid, calculatorTid, customerTid;
  SPSafePthreadMutex buff1Mutex, buff2Mutex, ioMutex;
  SPSafePthreadCond waitBuff1Full, waitBuff1Empty, waitBuff2Full, waitBuff2Empty;
  PC1Buff buff1, buff2;
  volatile bool producerFinish, calculatorFinish;
};

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