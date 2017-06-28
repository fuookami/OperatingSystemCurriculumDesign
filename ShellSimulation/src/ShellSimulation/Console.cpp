#include "Console.h"
#include <iostream>
#include <regex>

void Console::run()
{
	Cmd *pCmd = Cmd::getInstance();

	std::string line;

	std::cout << Command::dir << "$ ";

	while (std::getline(std::cin, line))
	{
		std::deque<std::deque<std::string>> args(split(line));
		std::deque<pipe> pipes(generatePipes(args));

		for (unsigned long i(0), j(pipes.size()); i != j; ++i)
		{
			std::string command(pipes[i].args[0]);
			pipes[i].args.pop_front();

			Retcode ret;
			if (pipes[i].is == nullptr)
				ret = pCmd->runCommand(
					std::cin, (*(pipes[i].os)), command, pipes[i].args
				);
			else
				ret = pCmd->runCommand(
					(*(pipes[i].is)), (*(pipes[i].os)), command, pipes[i].args
				);

			if (i + 1 != j)
				pipes[i + 1].is = new std::istringstream(pipes[i].os->str());

			if (ret == Retcodes::EXIT)
				return;
		}

		if (fout.is_open())
		{
			fout << pipes.back().os->str();
			fout.close();
		}
		else
			std::cout << pipes.back().os->str();
	}

	return;
}

std::deque<std::deque<std::string>> Console::split(const std::string &str)
{
	std::deque<std::deque<std::string>> ret;
	ret.push_back(std::deque<std::string>());
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
			std::smatch cm;
			if (regex_search(currIt, edIt, cm, regexs[i], std::regex_constants::match_continuous))
			{
				currIt += cm[0].str().size();
				if (cm[0].str() == "|")
					ret.push_back(std::deque<std::string>());

				ret.back().push_back(std::move(cm[0].str()));
				break;
			}
		}
	}
}

std::deque<pipe> Console::generatePipes(std::deque<std::deque<std::string>> args)
{
	std::deque<pipe> pipes(args.size(), pipe());
	for (unsigned long i(0), j(args.size()); i != j; ++i)
	{
		pipes.push_back(
			{
				args[i],
				nullptr,
				new std::ostringstream()
			});
	}

	std::string input(findInput(args.front()));
	if (!input.empty())
	{
		std::ostringstream buff;
		std::ifstream fin(input);
		buff << fin.rdbuf();
		pipes.front().is = new std::istringstream(buff.str());
	}

	std::string output(findOutput(args.back()));
	if (!output.empty())
	{
		fout.open(output);
	}

	return std::move(pipes);
}

std::string Console::findInput(std::deque<std::string> &args)
{
	std::string ret;
	for (std::deque<std::string>::iterator currIt(args.begin()),
		edIt(args.end()); currIt != edIt; ++currIt)
	{
		if ((*currIt)[0] == '<')
		{
			ret = *currIt;
			ret.erase(ret.begin());
			args.erase(currIt);
			break;
		}
	}

	return std::move(ret);
}

std::string Console::findOutput(std::deque<std::string> &args)
{
	std::string ret;
	for (std::deque<std::string>::iterator currIt(args.begin()),
		     edIt(args.end()); currIt != edIt; ++currIt)
	{
		if ((*currIt)[0] == '>')
		{
			ret = *currIt;
			ret.erase(ret.begin());
			args.erase(currIt);
			break;
		}
	}

	return std::move(ret);
}