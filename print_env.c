#include "shell.h"

/**
* print_env - Print the env varaible
*
* Return: 0 (succes)
*/
int print_env(void)
{
	int i;

	for (i = 0; new_env[i]; i++)
	{
		if (new_env[i][0] != '\0')
		{
			write(STDOUT_FILENO, new_env[i], _strlen(new_env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	return (0);
}
