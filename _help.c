#include "shell.h"

/**
* _help - Check the help, refer to help function
*
* Return: 1 succes
*/
int _help(void)
{
	if (array_command[2] == NULL)
	{
		if (_strcmp(array_command[1], "exit") == 0)
			_help_exit();
		else if (_strcmp(array_command[1], "env") == 0)
			_help_env();
		else if (_strcmp(array_command[1], "setenv") == 0)
			_help_setenv();
		else if (_strcmp(array_command[1], "unsetenv") == 0)
			_help_unsetenv();
		else if (_strcmp(array_command[1], "cd") == 0)
			_help_cd();
		else
			_help_error();
	}
	else
		_help_error();
	return (1);
}

/**
* _help_error - Print the error
*
* Return: Anything, cause void function
*/
void _help_error(void)
{
		write(STDERR_FILENO, "\nError syntaxe : help [BUILT-IN]\n", 33);
		write(STDERR_FILENO, "\n   Built-in command :\n\texit\n\tenv\n\tsetenv", 42);
		write(STDERR_FILENO, "\n\tnsetenv\n\tcd\n\n", 15);
}
