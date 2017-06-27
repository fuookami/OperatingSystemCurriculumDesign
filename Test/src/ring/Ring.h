//
// Created by fuookami on 17-6-27.
//

#pragma once
#include "Data.h"
#include "SafePthreadExtra.h"

class RingThread
{
 public:
  RingThread(unsigned int threadId);
  ~RingThread();

  void start(RingThread *nextThread);
  void join(void);
  void receive(const Data &d);

 protected:
  static void *run(void *args);

 private:
  void printMsg(const std::string &str);

 private:
  unsigned int id;
  Data data;
  pthread_t tid;
  SPSafePthreadSema sema;
};

class Ring
{
 public:
  ~Ring();

  Ring &getReference(void);
  void run();

 private:
  Ring();

 private:
  std::vector<RingThread> threads;
};