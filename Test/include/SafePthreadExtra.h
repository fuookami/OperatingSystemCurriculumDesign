//
// Created by fuookami on 17-6-25.
//

#pragma once


#include <memory>
#include <pthread.h>

using routine_t = void *(void *);

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

pthread_mutex_t &SafePthreadMutex::get()
{
	return mutex;
}

pthread_mutex_t *SafePthreadMutex::getPtr()
{
	return &mutex;
}

bool SafePthreadMutex::lock()
{
	return pthread_mutex_lock(&mutex) == 0;
}

bool SafePthreadMutex::unlock()
{
	return pthread_mutex_unlock(&mutex) == 0;
}

bool SafePthreadMutex::success() const
{
	return initSuccess;
}

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

class SafePthreadSema
{
 public:
  static std::shared_ptr<SafePthreadSema> create(int _value = 0, pthread_mutexattr_t *mutexAttr = nullptr,
                                                 pthread_condattr_t *condAttr = nullptr);
  ~SafePthreadSema();

  inline SafePthreadMutex &getSafeMutex(void);
  inline SpSafePthreadMutex getSafeMutexSPtr(void);
  inline SafePthreadCond &getSafeCond(void);
  inline SPSafePthreadCond getSafeCondSPtr(void);
  inline int value(void) const;

  bool wait(SafePthreadSema &rop);
  bool wait(std::shared_ptr<SafePthreadSema> &prop);

  bool signal(SafePthreadSema &rop);
  bool signal(std::shared_ptr<SafePthreadSema> &prop);

 private:
  SafePthreadSema(int value = 0, pthread_mutexattr_t *mutexAttr = nullptr,
                  pthread_condattr_t *condAttr = nullptr);
  inline bool success(void) const;

 private:
  int value;
  bool initSuccess;
  SPSafePthreadMutex spMutex;
  SPSafePthreadCond spCond;
};

pthread_cond_t& SafePthreadCond::get()
{
	return cond;
}

pthread_cond_t* SafePthreadCond::getPtr()
{
	return &cond;
}

bool SafePthreadCond::wait(pthread_mutex_t *pMutex)
{
	return pthread_cond_wait(&cond, pMutex) == 0;
}

bool SafePthreadCond::wait(SafePthreadMutex *pSafeMutex)
{
	return pthread_cond_wait(&cond, pSafeMutex->getPtr()) == 0;
}

bool SafePthreadCond::wait(std::shared_ptr<SafePthreadMutex> &spSafeMutex)
{
	return pthread_cond_wait(&cond, spSafeMutex->getPtr()) == 0;
}

bool SafePthreadCond::signal()
{
	return pthread_cond_signal(&cond) == 0;
}

bool SafePthreadCond::broadcast()
{
	return pthread_cond_broadcast(&cond) == 0;
}

bool SafePthreadCond::success() const
{
	return initSuccess;
}

SafePthreadMutex &SafePthreadSema::getSafeMutex(void)
{
  return *spMutex;
}

SPSafePthreadMutex SafePthreadSema::getSafeMutexSPtr(void)
{
  return spMutex;
}

SafePthreadCond &SafePthreadSema::getSafeCond(void)
{
  return *spCond;
}

SpSafePthreadCond SafePthreadSema::getSafeCondSPtr(void)
{
  return spCond;
}

int SafePthreadSema::values(void) const
{
	return values;
}

bool SafePthreadSema::success(void) const
{
  return initSuccess;
}