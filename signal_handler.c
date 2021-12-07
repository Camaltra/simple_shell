#include "shell.h"

/**
* signal_handler - Catch a Ctrl - C
*
* @i: Useless parameter
*
* Return: Anything, cause void function
*/
void signal_handler(__attribute__((unused)) int i)
{
	write(STDOUT_FILENO, "\n", 1);
	_prompt();
}
