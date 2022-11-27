#include "main.h"

/**
 * errputs - writes a string to standard error
 * @s: string to print
 * Return: number of bytes written or -1 on failure
 */

int errputs(char *s)
{
	int nwrite, len = strlen(s);

	nwrite = write(2, s, len);

	return (nwrite);
}

/**
 *
 */

/*int print_err(char **arg, char *buf)
{
	char *s;
*/

int main(void)
{
	char *s = "hi\n";

	errputs(s);
	return (0);
}
