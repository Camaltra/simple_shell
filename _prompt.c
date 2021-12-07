#include "shell.h"

/**
* _prompt - Prompt the PWD env var, and $, to make our
* simple shell realistic
*
* Return: Anything, cause void function
*/
void _prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, _getenv("PWD"), _strlen(_getenv("PWD")));
		write(STDOUT_FILENO, "$ ", 2);
	}
}
