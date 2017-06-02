#include "Cmd.h"

std::shared_ptr<Cmd> Cmd::mInstance = nullptr;

Cmd * Cmd::getInstance(std::istream & _in, std::ostream & _out)
{
	mInstance.reset(new Cmd(_in, _out));

	return mInstance.get();
}

Cmd * Cmd::getInstance(void)
{
	if (mInstance == nullptr)
		mInstance.reset(new Cmd());
	return mInstance.get();
}

Cmd::Cmd(void) 
	: in(std::cin), out(std::cout)
{
	char szWorkDir[MaxDirLength] = {0} ;
	getcwd(szWorkDir, MaxDirLength);
	Command::dir.assign(szWorkDir, MaxDirLength);
}

int Cmd::runCommand(const std::string &command, const std::deque<std::string>& args)
{
	Command::CommandMap::const_iterator funIt(Command::commandMap.find(command));
	if (funIt == Command::commandMap.cend())
	{
		printRet(command, Command::Retcodes::CMD_ERROR);
		return Command::Retcodes::CMD_ERROR;
	}

	Retcode retCode(funIt->second(out, args));
	printRet(command, retCode);
	return retCode;
}

void Cmd::printRet(const std::string &command, const Retcode retCode)
{
	switch (retCode)
	{
		case Command::Retcodes::ARG_ERROR:
			out << " : illegal argument" << std::endl;
			break;
		case Command::Retcodes::CMD_ERROR:
			out << command << " : command not fount" << std::endl;
			break;
		case Command::Retcodes::FILE_CAN_NOT_FOUNT:
			out << " : file can not be fount" << std::endl;
			break;
		case Command::Retcodes::FILE_CAN_NOT_BE_READ:
			out << " : fIle can not be read" << std::endl;
			break;
		case Command::Retcodes::FILE_CAN_NOT_BE_CREATED:
			out << " : file can not be created" << std::endl;
		case Command::Retcodes::EXIT:
		case Command::Retcodes::NO_ERROR:
		default:
			break;
	}
}
