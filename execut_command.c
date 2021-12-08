#include "shell.h"

/**
* execut_command - Test and execute a command
*
* Return: Anything, cause void function
*/
void execut_command(void)
{
	int (*f)(void), a = 0, b = 0, c = 0;
	struct stat st;

	if (_strcmp(array_command[0], "echo") == 0)
	{
		a = echo_dollar();
		c = echo_exit_status();
		if (c != 1)
			b = echo_var();
		if (a == 1 || b == 1 || c == 1)
		{
			free_command();
			return;
		}
	}
	f = check_built_in(array_command[0]);
	if (f != NULL)
	{
		f();
		free_command();
		return;
	}
	else if (search_command_path(array_command[0]) != 1)
	{
		_exevc();
		free_command();
		return;
	}
	else if (stat(array_command[0], &st) == 0)
	{
		_exevc();
		free_command();
		return;
	}
	else
	{
		error_execut();
		exit_var = 2;
		free_command();
	}
}

/**
* error_execut - Print a error message to STDERR, that explain
* why it doesn't work
*
* Return: Anything, cause void function
*/
void error_execut(void)
{
	int i;
	char count;

	for (i = 0; array_command[i]; i++)
		;
	i -= 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			write(STDERR_FILENO, array_command[0], _strlen(array_command[0]));
			write(STDERR_FILENO, ": not found\n", 12);
		}
		else
		{
			count = i + 48;
			write(STDERR_FILENO, array_command[i], _strlen(array_command[i]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, &count, 1);
			write(STDERR_FILENO, ": ", 2);
		}
		i--;
	}
}
