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
void execmd(char **arg, char *buf);
char *_getenv(char *name);
void prompt(void);
char *_read(void);
int handle_builtin(char **arg, char *buf);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
extern char **environ;
#endif
