#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>

char *_strcpy(char *dest, char *src);
char *_strdup(char *src);
char *_strtok(char *str, char *delim);
int _strlen(char *c);
char **tokenz(int *argc, char *read, char *delim);
void _execute(char **argv);
char* read_input();

#endif






