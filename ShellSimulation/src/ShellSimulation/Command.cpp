#include "Command.h"

#include "unistd.h"
#include <numeric>

Retcode Command::myecho(std::istream &is, std::ostream &os, const std::deque<std::string> &args)
{
	if (args.size() == 0)
		return Retcodes::ARG_NUM_ERROR;

	for (unsigned long i(0), j(args.size()); i != j; ++i)
		os << args[i] << ' ';

	return Retcodes::NO_ERROR;
}

Retcode Command::mycat(std::istream &is, std::ostream &os, const std::deque<std::string> &args)
{

}

Retcode Command::mycp(std::istream &is, std::ostream &os, const std::deque<std::string> &args)
{

}

Retcode Command::myexit(std::istream &is, std::ostream &os, const std::deque<std::string> &args)
{
    if (args.size() == 0)
    {
        return Retcodes::EXIT;
    }
}

int mysys(const std::string &command, const std::deque<std::string> &args)
{
	char **argv(new char *[args.size() + 1]);
	argv[args.size()] = NULL;
	for (unsigned long i(0), j(args.size()); i != j; ++i)
	{
		argv[i] = const_cast<char *>(args[i].c_str());
	}

	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		execvp(("/bin/" + command).c_str(), argv);
		delete[] argv;
	}
	return 0;
}