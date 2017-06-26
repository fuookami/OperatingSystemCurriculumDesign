//
// Created by fuookami on 17-6-25.
//

#pragma once
#include "SafePthreadExtra.h"
#include "PCBuffer.h"

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
  PCBuffer buff1, buff2;
  volatile bool producerFinish, calculatorFinish;
};