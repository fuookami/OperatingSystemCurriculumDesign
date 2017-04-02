#pragma once

#include "SingleTon.h"
#include "Command.h"

class Cmd
{
	friend class SingleTon<Cmd>;

private:
	Cmd(void);

public:
	~Cmd(void) {}

public:
	int runCommand(const std::string command, const std::deque<std::string> &args);

private:
	Command::CommandMap commandMap;
};