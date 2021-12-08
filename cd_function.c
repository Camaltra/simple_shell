#include "shell.h"

/**
* cd_function - recreate cd function
*
* Return: nothing
*/
int cd_function(void)
{
	char hyphen[] = "-";
	char *buff = malloc(sizeof(char) * 1024);

	if (array_command[1] == NULL)
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir("/home/vagrant");
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}
	else if (strcmp(array_command[1], hyphen) == 0)
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir("..");
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}
	else
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir(array_command[1]);
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}

	free(buff);
	return (0);
}
