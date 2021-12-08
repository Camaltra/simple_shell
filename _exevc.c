#include "shell.h"

/**
 * _exevc - Run a command into a child process
 *
 * Return: Anything, cause void function
 */
void _exevc(void)
{
	pid_t child;
	int status;

	child = fork();

	if (child == 0)
	{
		if (execve(array_command[0], array_command, new_env))
		{
			exit_var = 2;
			exit(EXIT_FAILURE);
		}
		exit_var = 0;
	}
	if (child > 0)
		wait(&status);
}
