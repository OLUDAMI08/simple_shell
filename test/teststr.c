#include "main.h"

int main()
{
	char *s[] = {"hey", "hi"};
	s[0] = "yeh";
	int x = strlen(s[0]);

	printf("s: %s\n", s[0]);
	printf("x: %d\n", x);
	return (0);
}
