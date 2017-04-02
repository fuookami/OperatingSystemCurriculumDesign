#include "Cmd.h"

Cmd::Cmd(void)
{
	for (const Command::Command2Fun &command2Fun : Command::command2Funs)
		commandMap.insert(command2Fun);
}

int Cmd::runCommand(const std::string command, const std::deque<std::string>& args)
{
	return commandMap[command](args);
}
