#include "shell.h"

/**
 * _exit_ - Exit the shell system
 *
 * Return: 0 (succes)
 */
int _exit_(void)
{
	int error_status;

	if (array_command[1] == NULL)
	{
		free_all();
		exit(0);
	}
	else
	{
		error_status = _atoi(array_command[1]);
		free_all();
		exit(error_status);
	}
	return (0);
}
