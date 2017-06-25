//
// Created by fuookami on 17-6-25.
//

#pragma once

#include <memory>
#include <pthread.h>

class SafePthreadMutex
{
 public:
  static std::shared_ptr<SafePthreadMutex> create(pthread_mutexattr_t *attr = nullptr);
  ~SafePthreadMutex();

  inline pthread_mutex_t &get(void);
  inline pthread_mutex_t *getPtr(void);

  inline bool lock(void);
  inline bool unlock(void);

 private:
  SafePthreadMutex(pthread_mutexattr_t *attr = nullptr);
  inline bool success(void) const;

 private:
  bool initSuccess;
  pthread_mutex_t mutex;
};
using SPSafePthreadMutex = std::shared_ptr<SafePthreadMutex>;

class SafePthreadCond
{
 public:
  static std::shared_ptr<SafePthreadCond> create(pthread_condattr_t *attr = nullptr);
  ~SafePthreadCond();

  inline pthread_cond_t &get(void);
  inline pthread_cond_t *getPtr(void);

  inline bool wait(pthread_mutex_t *pMutex);
  inline bool wait(SafePthreadMutex *pSafeMutex);
  inline bool wait(std::shared_ptr<SafePthreadMutex> &spSafeMutex);

  inline bool signal(void);
  inline bool broadcast(void);

 private:
  SafePthreadCond(pthread_condattr_t *attr = nullptr);
  inline bool success(void) const;

 private:
  bool initSuccess;
  pthread_cond_t cond;
};
using SPSafePthreadCond = std::shared_ptr<SafePthreadCond>;