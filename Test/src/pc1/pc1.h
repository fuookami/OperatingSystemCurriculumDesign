//
// Created by fuookami on 17-6-25.
//

#pragma once
#include <iostream>
#include <deque>

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
  PC1(void);
  ~PC1();

  void run();
 private:
  PC1Buff buff1, buff2;
};