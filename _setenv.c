#include "shell.h"

/**
* _setenv - Set an env variable, create it if not exit, else
* change the value
*
* Return: 0 (succes), 1 else. If malloc issues, exit.
*/
int _setenv(void)
{
	int i;
	int length;

	if (array_command[1] == NULL || array_command[2] == NULL)
	{
		error_setenv();
		return (-1);
	}
	if (_getenv(array_command[1]) != NULL)
		i = _setenv_exist(array_command[1]);

	else
		i = _setenv_not_exist();
	length = _strlen(array_command[1]) + _strlen(array_command[2]) + 2;
	new_env[i] = malloc(sizeof(char) * length);
	init_new_env(i);
	return (0);
}
