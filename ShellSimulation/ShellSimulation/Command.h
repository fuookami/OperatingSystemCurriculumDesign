#pragma once

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <map>

namespace Command
{
	using CommandFun = int(const std::deque<std::string> &args);
	using pCommandFun = CommandFun *;
	using Command2Fun = std::pair<std::string, pCommandFun>;
	using CommandMap = std::map<std::string, pCommandFun>;

	int myecho(const std::deque<std::string> &args);
	int mycat(const std::deque<std::string> &args);
	int mycp(const std::deque<std::string> &args);

	static const std::vector<Command2Fun> command2Funs(
	{
		std::make_pair(std::string("myecho"), &myecho),
		std::make_pair(std::string("mycat"), &mycat),
		std::make_pair(std::string("mycp"), &mycp),
	});
}