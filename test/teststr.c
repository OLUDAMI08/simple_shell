#include "main.h"

int main()
{
	char *s[] = {"hey", "hi"};
	s[0] = "yeh";

	printf("s: %s\n", s[0]);
	return (0);
}
