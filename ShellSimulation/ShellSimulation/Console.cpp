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

std::deque<std::string> split(const std::string &source)
{
    // todo add rego to ""

	size_t las(0), pos(0);
	std::deque<std::string> dest;
	for (; (pos = source.find(str, pos)) != std::string::npos; )
	{
		if (las != pos)
		{
			dest.push_back(std::string(source, las, pos - las));
		}
		pos += str.size();
		las = pos;
	}
	std::string temp(std::string(source, las, source.size() - las));
	if (!temp.empty() && temp != str)
	{
		dest.push_back(move(temp));
	}

	return std::move(dest);
}