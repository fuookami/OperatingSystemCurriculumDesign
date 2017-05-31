#pragma once

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <unordered_map>

using Retcode = unsigned int;

namespace Command
{
	using CommandFun = int(*)(std::ostream &out, const std::deque<std::string> &args);
	using Command2Fun = std::pair<std::string, CommandFun>;
	using CommandMap = std::unordered_map<std::string, CommandFun>;
	static std::string dir;

	enum Retcodes
	{
		EXIT = -1,
		NO_ERROR = 0,
		CMD_ERROR = 1,
		ARG_ERROR = 2,
		FILE_CAN_NOT_FOUNT = 3
	};

	int myecho(std::ostream &out, const std::deque<std::string> &args);
	int mycat(std::ostream &out, const std::deque<std::string> &args);
	int mycp(std::ostream &out, const std::deque<std::string> &args);
	int myexit(std::ostream &out, const std::deque<std::string> &args);

	static const CommandMap commandMap(
	{
		std::make_pair(std::string("myecho"), &myecho),
		std::make_pair(std::string("mycat"), &mycat),
		std::make_pair(std::string("mycp"), &mycp),
		std::make_pair(std::string("myexit"), &myexit),
	});
}