#pragma once

#include "SingleTon.h"
#include "Command.h"
#include <iostream>

class Cmd
{
	friend class SingleTon<Cmd>;
	friend class Console;

private:
	Cmd(std::istream &_in, std::ostream &_out) : in(_in), out(_out) {}
	Cmd(void);

public:
	~Cmd(void) {}
	static const unsigned int MaxDirLength = 256;

private:
	static Cmd *getInstance(std::istream &_in, std::ostream &_out);
	static Cmd *getInstance(void);

	int runCommand(const std::string &command, const std::deque<std::string> &args);
	void printRet(const std::string &command, const Retcode retCode);

private:
	static std::shared_ptr<Cmd> mInstance;

	std::istream &in;
	std::ostream &out;
};