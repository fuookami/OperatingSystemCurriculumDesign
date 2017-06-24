#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	int fileCode(open(argv[1], O_RDONLY));
	if (fileCode == -1)
	{
		std::cout << argv[1];
		return 3;
	}

	off_t fileSize(lseek(fileCode, 0, SEEK_END));
	lseek(fileCode, 0, SEEK_SET);
	char *buff(new char[fileSize + 1]);
	buff[fileSize] = '\0';

	ssize_t readNum(read(fileCode, (void *)buff, (size_t)fileSize));
	if ((size_t)readNum == 0)
	{
		std::cout << argv[1];
		return 4;
	}

	std::cout << buff << std::endl;
	close(fileCode);
	return 0;
}