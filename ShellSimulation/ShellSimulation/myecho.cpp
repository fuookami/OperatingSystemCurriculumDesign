#include "Command.h"

#include <iostream>

int Command::myecho(const std::deque<std::string> &args)
{
	for (size_t i(0), j(args.size() - 1); i != j; ++i)
	{
		std::cout << args[i];
	}
	std::cout << args.back();

	return 0;
}