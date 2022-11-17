#include "main.h"
/**
* prompt - prints a prompt on the terminal
*/

void prompt(void)
{
	char *prompt = "($) ";
	ssize_t nwrite = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		nwrite = write(STDOUT_FILENO, prompt, 2);
		if (nwrite = -1)
			exit(0);
	}
}
