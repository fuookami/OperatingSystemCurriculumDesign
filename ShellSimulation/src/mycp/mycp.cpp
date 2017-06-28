#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "RetCodes.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
		return Retcodes::ARG_NUM_ERROR;

	int inFileCode = open(argv[1], O_RDONLY);
	if (inFileCode == -1)
		return Retcodes::FILE_CAN_NOT_FOUNT;

	int outFileCode = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC);
	if (outFileCode == -1)
		return Retcodes::FILE_CAN_NOT_BE_CREATED;

	size_t fileSize((size_t)lseek(inFileCode, 0, SEEK_END));
	lseek(inFileCode, 0, SEEK_SET);
	char *buff(new char[fileSize + 1]);
	buff[fileSize] = '\0';

	ssize_t readNum(read(inFileCode, (void *)buff, fileSize));
	if ((size_t)readNum == 0)
		return Retcodes::FILE_CAN_NOT_BE_READ;

	ssize_t writeNum(write(outFileCode, buff, fileSize));
	if ((size_t)writeNum == 0)
		return Retcodes::FILE_CAN_NOT_BE_WRITEN;

	close(inFileCode);
	close(outFileCode);
	return Retcodes::NO_ERROR;
}