#pragma once

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <unordered_map>

namespace Command
{
	using CommandFun = int(*)(const std::deque<std::string> &args);
	using Command2Fun = std::pair<std::string, pCommandFun>;
	using CommandMap = std::unordered_map<std::string, pCommandFun>;
	static std::string dir;

	enum Retcodes
	{
		EXIT = -1,
		NO_ERROR = 0,
		CMD_ERROR = 1,
		ARG_ERROR = 2,
		FILE_CAN_NOT_FOUNT = 3
	};

	int myecho(const std::deque<std::string> &args);
	int mycat(const std::deque<std::string> &args);
	int mycp(const std::deque<std::string> &args);
	int myexit(const std::deque<std::string> &args);

	static const CommandMap command2Funs(
	{
		std::make_pair(std::string("myecho"), &myecho),
		std::make_pair(std::string("mycat"), &mycat),
		std::make_pair(std::string("mycp"), &mycp),
		std::make_pair(std::string("myexit"), &myexit),
	});
}