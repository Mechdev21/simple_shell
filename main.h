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
/**
 * struct shell - node that contains the directory
 * @dic: directory
 * @next: link to next node
 */
typedef struct shell
{char *dic;
struct shell *next;
} shell_t;
/**
* struct formats - struct formats
* @ch: pointer to firts element.
* @func: The function associated.
*/
typedef struct formats
	{
		char *ch;
		int (*func)();
	} form;

void check_id(int cue);
int _funcexit(char *cmdline);
int _shellenv(char *cmdline, int count, char **argline, char **path);
char *_findenv(const char *env_name);
char **linetoken(char *cmd_line);
ssize_t _getline(char **buf, size_t *size, FILE *stream);
char *_search(shell_t **head, char *argv);
int execute_cmd(char **argcmd, char **argv, int count);
char *exec_cmd(char *argv);
char *find_path(char *argv);
int _findcha();
int _putchar(char c);
int _printf(const char *format, ...);
int p_aux_int(long int n, long int);
int _pstr(va_list args);
int _pchar(va_list args);
int _pint(va_list args);
extern char **environ;
char *_strcat(char *directory, char *slash, char *arg);
shell_t *_chain(char *a);
void free_list(shell_t *head);
shell_t *_add_nodeint_end(shell_t **head, char *d);



#endif






