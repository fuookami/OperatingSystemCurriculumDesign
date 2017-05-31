#include "Console.h"

int main(int argc, char *argv[])
{
	Console *pConsole = SingleTon<Console>::getInstance();
	pConsole->run(std::cin, std::cout);

	return 0;
}