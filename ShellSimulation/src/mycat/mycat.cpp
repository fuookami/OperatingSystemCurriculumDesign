#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
		return Retcodes::ARG_NUM_ERROR;

	int fileCode(open(argv[1], O_RDONLY));
	if (fileCode == -1)
		return Retcodes::FILE_CAN_NOT_FOUNT;

	off_t fileSize(lseek(fileCode, 0, SEEK_END));
	lseek(fileCode, 0, SEEK_SET);
	char *buff(new char[fileSize + 1]);
	buff[fileSize] = '\0';

	ssize_t readNum(read(fileCode, (void *)buff, (size_t)fileSize));
	if ((size_t)readNum == 0)
		return Retcodes::FILE_CAN_NOT_BE_READ;

	std::cout << buff << std::endl;
	close(fileCode);
	return Retcodes::NO_ERROR;
}