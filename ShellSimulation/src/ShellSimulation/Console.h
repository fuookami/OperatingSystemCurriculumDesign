#pragma once

#include "Cmd.h"
#include <iostream>
#include <fstream>
#include <sstream>

struct pipe
{
  std::deque<std::string> args;
  std::istringstream *is;
  std::ostringstream *os;
};

class Console
{
	friend class SingleTon<Console>;

 private:
  Console() : pCmd(nullptr) {}

 public:
  ~Console() {}

  void run();

 private:
  std::deque<std::deque<std::string>> split(const std::string &source);
  std::deque<pipe> generatePipes(std::deque<std::deque<std::string>> args);
  std::string findInput(std::deque<std::string> &args);
  std::string findOutput(std::deque<std::string> &args);

 private:
  Cmd *pCmd;
  std::ofstream fout;
};