#include "Command.h"

#include <numeric>

int Command::myecho(std::ostream &out, const std::deque<std::string> &args)
{
    execl((dir + "/bin/myecho/").c_str(), "myecho",
        std::accumulate(args.cbegin(), args.cend(), std::string("")).c_str(), NULL);
}

int Command::mycat(std::ostream &out, const std::deque<std::string> &args)
{

}

int Command::mycp(std::ostream &out, const std::deque<std::string> &args)
{

}

int Command::myexit(std::ostream &out, const std::deque<std::string> &args)
{
    if (args.size() == 0)
    {
        return -1;
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