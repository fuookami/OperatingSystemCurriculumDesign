#include "Console.h"

int main(int argc, char *argv[])
{
	Console *pConsole = SingleTon<Console>::instance();
	pConsole->run();

	return 0;
}