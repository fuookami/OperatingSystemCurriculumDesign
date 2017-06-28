#pragma once

#include "SingleTon.h"
#include "Command.h"
class Cmd
{
	friend class SingleTon<Cmd>;
	friend class Console;

private:
	Cmd(void);

public:
	~Cmd(void) {}
	static const unsigned int MaxDirLength = 256;

private:
	static Cmd *getInstance(void);

	Retcode runCommand(std::istream &is, std::ostream &os, const std::string &command, const std::deque<std::string> &args);

private:
	static std::shared_ptr<Cmd> mInstance;
};