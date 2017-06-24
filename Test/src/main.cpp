#include <iostream>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <deque>
#include <string>
#include <regex>
#include <random>
#include "MultiThreadSort.h"

char szWorkDir[256] = {0} ;

void myecho_test()
{
	std::string echoPath(szWorkDir);
	echoPath += "/bin/";
	execl(echoPath.c_str(), "myecho", "app1", NULL);
	return;
}

void mycat_test()
{
	std::string catPath(szWorkDir);
	std::string dirPathCopy(szWorkDir);
	catPath += "/bin/";
	dirPathCopy += "/test.txt";
	execl(catPath.c_str(), "mycat", dirPathCopy.c_str(), NULL);
}

void mycp_test()
{
	std::string cpPath(szWorkDir);
	std::string inFilePath(szWorkDir);
	std::string outFilePath(szWorkDir);
	cpPath += "/bin/";
	inFilePath += "/test.txt";
	outFilePath += "/out.txt";
	execl(cpPath.c_str(), "mycp", inFilePath.c_str(), outFilePath.c_str(), NULL);
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

void mysys_test()
{
	std::deque<std::string> args;
	//args.push_back("echo");
	//args.push_back("arg1");
	//args.push_back("arg2");
	//args.push_back("arg3");
	//args.push_back("ls");
	//mysys("ls", args);
}

std::deque<std::string> split(const std::string &str)
{
	std::deque<std::string> ret;
	static const std::vector<std::regex> regexs = {
		std::regex(std::string("\"[^\"]*\"")),
	    std::regex(std::string("[\\S]*[\\s]?")),
	};
	for (std::string::const_iterator currIt(str.cbegin()),
		edIt(str.cend()); currIt != edIt; )
	{
		if (isspace(*currIt))
		{
			++currIt;
			continue;
		}

		for (unsigned long i(0), j(regexs.size()); i != j; ++i)
		{
			std::cout << i << std::endl;
			std::smatch cm;
			if (regex_search(currIt, edIt, cm, regexs[i], std::regex_constants::match_continuous))
			{
				currIt += cm[0].str().size();
				ret.push_back(std::move(cm[0].str()));
				break;
			}
		}
	}

	return std::move(ret);
}

void split_test()
{
	std::deque<std::string> result(split(std::string("echo arg1 \"arg2 arg3\" f\"a\"")));
	for (unsigned long i(0), j(result.size());i != j; ++i)
		std::cout << i << " : " << result[i] << std::endl;
}

void sort_test()
{
	std::random_device rd;
	std::vector<int> nums;
	for (unsigned long i(0), j(10); i != j; ++i)
	{
		nums.push_back(rd() % 20);
		std::cout << nums[i] << ' ';
	}
	std::cout << std::endl;


	MultiThreadSort::sort(nums.begin(), nums.end());

	for (unsigned long i(0), j(nums.size()); i != j; ++i)
		std::cout << nums[i] << ' ';
	std::cout << std::endl;
}

int main() {
	getcwd(szWorkDir, 256);
	//myecho_test();
	//mycat_test();
	//mycp_test();
	//mysys_test();
	//split_test();
	sort_test();

	return 0;
}