#include "Public.h"
#include <memory>

std::deque<std::string> split(const std::string & source, const std::string &str)
{
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