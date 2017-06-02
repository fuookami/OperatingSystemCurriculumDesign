//
// Created by fuookami on 17-5-30.
//

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
	int inFileCode = open(argv[1], O_RDONLY);
	if (inFileCode == -1)
	{
		std::cout << argv[1];
		return 3;
	}

	int outFileCode = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC);
	if (outFileCode == -1)
	{
		std::cout << argv[2];
		return 5;
	}

	size_t fileSize((size_t)lseek(inFileCode, 0, SEEK_END));
	lseek(inFileCode, 0, SEEK_SET);
	char *buff(new char[fileSize + 1]);
	buff[fileSize] = '\0';

	ssize_t readNum(read(inFileCode, (void *)buff, fileSize));
	if ((size_t)readNum == 0)
	{
		std::cout << argv[1];
		return 4;
	}

	ssize_t writeNum(write(outFileCode, buff, fileSize));
	if ((size_t)writeNum == 0)
	{
		std::cout << argv[2];
		return 6;
	}

	close(inFileCode);
	close(outFileCode);
	return 0;
}