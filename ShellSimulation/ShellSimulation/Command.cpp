#include "Command.h"

#include <numeric>

int Command::myecho(const std::deque<std::string> &args)
{
    execl((dir + "/bin/myecho/").c_str(), "myecho",
        std::accumulate(args.cbegin(), args.cend(), std::string("")).c_str(), NULL);
}

int Command::mycat(const std::deque<std::string> &args)
{

}

int Command::mycp(const std::deque<std::string> &args)
{

}

int Command::exit(const std::deque<std::string> &args)
{
    if (args.size() == 0)
    {
        return -1;
    }
}