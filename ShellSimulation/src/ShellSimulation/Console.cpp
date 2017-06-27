#include "Console.h"

void Console::run(std::istream &in, std::ostream &out)
{
	Cmd *pCmd = Cmd::getInstance(in, out);

	std::string line;

	out << "$ ";

	while (std::getline(in, line))
	{
		std::deque<std::string> args(split(line));
		std::string command(args.front());
		args.pop_front();

		Retcode retCode = pCmd->runCommand(command, args);
		if (retCode == Command::Retcodes::EXIT)
			break;

		out << "$ ";
	}

	return;
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