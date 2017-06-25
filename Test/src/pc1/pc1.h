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

  bool isEmpty(void) const;
  bool isFull(void) const;
  unsigned long size(void) const;

  void push(const char ch);
  char pop(void);

 private:
  static const unsigned long buffSize = 4;
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