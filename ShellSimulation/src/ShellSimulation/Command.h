#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <unordered_map>
#include "RetCodes.h"

namespace Command
{
	using CommandFun = Retcode(*)(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	using Command2Fun = std::pair<std::string, CommandFun>;
	using CommandMap = std::unordered_map<std::string, CommandFun>;
	static std::string dir;

	Retcode myhelp(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode mysys(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode mycd(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode mypwd(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode myexit(std::istream &is, std::ostream &os, const std::deque<std::string> &args);

	Retcode myecho(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode mycat(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode mycp(std::istream &is, std::ostream &os, const std::deque<std::string> &args);

	Retcode sort_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode pi1_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode pi2_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode pc1_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode pc2_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);
	Retcode ring_test(std::istream &is, std::ostream &os, const std::deque<std::string> &args);

	static const CommandMap commandMap(
	{
		std::make_pair(std::string("myhelp"), &myhelp),
		std::make_pair(std::string("mysys"), &mysys),
		std::make_pair(std::string("mycd"), &mycd),
		std::make_pair(std::string("mypwd"), &mypwd),
		std::make_pair(std::string("myexit"), &myexit),

		std::make_pair(std::string("myecho"), &myecho),
		std::make_pair(std::string("mycat"), &mycat),
		std::make_pair(std::string("mycp"), &mycp),

		std::make_pair(std::string("sort_test"), &sort_test),
		std::make_pair(std::string("pi1_test"), &pi1_test),
		std::make_pair(std::string("pi2_test"), &pi2_test),
		std::make_pair(std::string("pc1_test"), &pc1_test),
		std::make_pair(std::string("pc2_test"), &pc2_test),
		std::make_pair(std::string("ring_test"), &ring_test),
	});
}