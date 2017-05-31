#pragma once

#include "SingleTon.h"
#include "Cmd.h"

class Console
{
	friend class SingleTon<Console>;

private:
	Console() : pCmd(nullptr) {}

public:
	~Console() {}

public:
	void run(std::istream &in, std::ostream &out);

private:
	Cmd *pCmd;

    std::deque<std::string> split(const std::string &source);
};