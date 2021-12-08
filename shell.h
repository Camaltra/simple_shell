#ifndef SHELL_H
#define SHELL_H

/* Include library */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define MALLOCSIZE 120

/* Struct */


/**
* struct path - Each node contain a directory of the PATH
*
* @current_dir: Str that contain a directory
* @next: Pointer to the next node
*/
typedef struct path
{
	char *current_dir;
	struct path *next;
} path;

/**
* struct built_in - Built in command
*
* @command: Command to check (without any flag)
* @f: Pointer to function to use
*/
typedef struct built_in
{
	char *command;
	int (*f)(void);
} built_in;


/* Variable global */


char **new_env;
path *path_head;
char **array_command;
char *user_input;
int exit_var;


/* Prototype */


/* ENV COMMAND */
void copy_env(char **env);
char *_getenv(const char *env);
int print_env(void);
int _setenv(void);
int _setenv_exist(char *name);
int _setenv_not_exist(void);
void init_new_env(int i);
void error_setenv(void);
int _unsetenv(void);

/* PROGRAM RUN COMMAD */
void init_path(void);
size_t print_list(const path *h);
int search_command_path(char *command);
int (*check_built_in(const char *command))(void);
int _exit_(void);
void loop_shell(char **env);
void _exevc(void);
void execut_command(void);
void signal_handler(__attribute__((unused)) int i);
int echo_dollar(void);
int echo_var(void);
int echo_exit_status(void);
void check_user_input(void);
void _prompt(void);
void error_execut(void);
ssize_t _getlines(char **lineptr, size_t *size, FILE *stream);
int my_fgetc(FILE *filename);
size_t _fread(void *buf, size_t count, FILE *filename);
int error_test(char *str);
void print_number(unsigned int number);
int _putchar(int c);

/* LINKED LIST USEFUL COMMAND */
path *add_node_end(path **head, char *str);

/* STR USEFULL COMMAND */
void strtow(char *str);
int _strlen_letter(char *s);
int _strcount_word(char *str);
int _strcmp(const char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
void sep_to_space(void);
int _atoi(char *s);

/* FREE COMMAND */
void free_list(path *head);
void free_all(void);
void free_command(void);
void free_env(void);
void free_path(void);

/* MEMORY FUNCTION */
char *_memcpy(char *dest, char *src);
void *_realloc(void *ptr, unsigned int new_size);
char **_realloc_pointer(char **ptr, unsigned int new_size);

/* HELP ASSORTMENT */
int _help(void);
void _help_error(void);
void _help_exit(void);
void _help_env(void);
void _help_setenv(void);
void _help_unsetenv(void);
void _help_cd(void);

#endif /* SHELL_H */
