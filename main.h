#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

char *getpath(char *cmd);
char **getcmd(char *lineptr_copy, const char *delim, ssize_t nread);
void execmd(char **arg);
char *_getenv(const char *name);
void prompt(void);

#endif
