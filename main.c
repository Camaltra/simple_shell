#include "shell.h"

/**
* main - Run the shell loop
*
* @ac: Number of arg
* @av: Value of arg, in a 2D array
* @env: Environement variable
*
* Return: 0 (succes);
*/
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	if (av[1] == NULL)
		loop_shell(env);
	else
		printf("Error syntaxe : ./simple_shell\n");
	return (0);
}

/**
* loop_shell - Run the shell until exit command
*
* @env: pointer of enviroment
*
* Return: Anything, cause void function
*/
void loop_shell(char **env)
{
	size_t number_of_bytes = 0;

	copy_env(env);
	init_path();
	do {
		_prompt();
		signal(SIGINT, signal_handler);
		if ((getline(&user_input, &number_of_bytes, stdin)) == -1)
		{
			free_env();
			free_path();
			free(user_input);
			break;
		}
		if (user_input[0] == '\n')
			continue;
		if (_strlen(user_input) >= 256)
		{
			write(STDERR_FILENO, "To much char, max size : 256\n", 29);
			continue;
		}
		check_user_input();
		strtow(user_input);
		execut_command();
		} while (1);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
}
