//
// Created by fuookami on 17-6-26.
//

#pragma once

#include "SafePthreadExtra.h"
#include "PCBuffer.h"

class PC2
{
 public:
  ~PC2();

  static PC2 &getReference();
  void run();

 private:
  PC2();

  static void *producer(void *args);
  static void *calculator(void *args);
  static void *customer(void *args);

  void printMsg(const std::string &msg);

 private:
  pthread_t producerTid, calculatorTid, customerTid;
  SPSafePthreadSema buff1MutexSema, buff2MutexSema;
  SPSafePthreadSema buff1EmptySema, buff1FullSema;
  SPSafePthreadSema buff2EmptySeam, buff2FullSema;
  PCBuffer buff1, buff2;
  volatile bool producerFinish, calculatorFinish;
};