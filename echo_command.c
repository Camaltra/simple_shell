#include "shell.h"

/**
* echo_dollar - Check if the command is "echo $$", then
* if it's the case, printf the pid
*
* Return: 1 succes, 0 not find
*/
int echo_dollar(void)
{
	pid_t my_pid = getpid();

	if (_strcmp(array_command[1], "$$") == 0)
	{
		printf("%u\n", my_pid);
		return (1);
	}
	return (0);
}

/**
* echo_var - Check if the command is "echo $env_var", then
* if it's the case, printf the env_var value.
*
* Return: 1 succes, 0 not find
*/
int echo_var(void)
{
	char *env;

	if (array_command[1][0] == '$')
	{
		env = _getenv(*(array_command + 1) + 1);
		if (env != NULL && _strcmp(env, "?") != 0)
		{
			write(STDOUT_FILENO, env, _strlen(env));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	return (0);
}

/**
* echo_exit_status - Print the exit status of a command
*
* Return: 1 if it's work, 0 else
*/
int echo_exit_status(void)
{
	if (_strcmp(array_command[1], "$?") == 0)
	{
		write(STDOUT_FILENO, "0\n", 2);
		return (1);
	}
	return (0);
}
