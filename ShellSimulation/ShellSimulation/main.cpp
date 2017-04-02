#include "Public.h"
#include "Cmd.h"
#include <iostream>
#include <deque>

int main(int argc, char *argv[])
{
	Cmd *pCmd = SingleTon<Cmd>::instance();
	std::string line;

	while (std::getline(std::cin, line))
	{
		std::deque<std::string> args(split(line));
		std::string command(args.front());
		args.pop_front();
		if (pCmd->runCommand(command, args) == -1)
			break;
	}

	return 0;
}