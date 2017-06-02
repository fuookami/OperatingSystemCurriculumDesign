//
// Created by fuookami on 17-5-30.
//

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

static const unsigned int BuffLen = 256;

int main(int argc, char *argv[])
{
	int fileCode = open(argv[1], O_RDONLY);
	if (fileCode == -1)
	{
		return 3;
	}

	char *buff(new char [BuffLen]);
	ssize_t readNum(0);
	while ((readNum = read(fileCode, (void *)buff, BuffLen)) != 0)
	{
		std::cout << buff;
	}
	return 0;
}