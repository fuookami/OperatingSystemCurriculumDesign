#include "Cmd.h"
#include <unistd.h>

std::shared_ptr<Cmd> Cmd::mInstance = nullptr;

Cmd * Cmd::getInstance(void)
{
	if (mInstance == nullptr)
		mInstance.reset(new Cmd());
	return mInstance.get();
}

Cmd::Cmd(void)
	: mInstance(nullptr)
{
	char szWorkDir[MaxDirLength] = {0} ;
	getcwd(szWorkDir, MaxDirLength);
	Command::dir.assign(szWorkDir);
}

Retcode Cmd::runCommand(std::istream &is, std::ostream &os, const std::string &command, const std::deque<std::string>& args)
{
	Command::CommandMap::const_iterator funIt(Command::commandMap.find(command));
	if (funIt == Command::commandMap.cend())
	{
		//printRet(command, Retcodes::CMD_ERROR);
		return Retcodes::CMD_ERROR;
	}

	Retcode retCode(funIt->second(is, os, args));
	return retCode;
}
