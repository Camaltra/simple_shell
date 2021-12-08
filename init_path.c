#include "shell.h"

/**
 * init_path - Initialise a linked list of the PATH contain
 *
 * Return: nothing, void function
 */
void init_path(void)
{
	char *path_value;
	int i = 0, j, k, length, checkpoint = 0;
	char *value_to_fill;

	path_head = NULL;
	if ((path_value = _getenv("PATH")))
	{
		for (i = 0; path_value[i]; i++)
		{
			if (path_value[i] == ':' || path_value[i] == '\0')
			{
				length = i - checkpoint + 2;
				value_to_fill = malloc(sizeof(char) * length);
				if (!value_to_fill)
					return;
				for (j = checkpoint, k = 0; j < i; j++, k++)
					value_to_fill[k] = path_value[j];
				if (value_to_fill[k - 1] != '/')
				{
					value_to_fill[k] = '/';
					value_to_fill[k + 1] = '\0';
				}
				else
					value_to_fill[k] = '\0';
				add_node_end(&path_head, value_to_fill);
				i++;
				checkpoint = i;
			}
		}
		add_last_path_value(path_value);
	}
}


void add_last_path_value(char *path_value)
{
	int i, j;
	char *value_to_fill;
	
	for (i = _strlen(path_value) - 1, j = 0; path_value[i] != ':'; i--, j++)
		;
	value_to_fill = malloc(sizeof(char) * j + 2);
	if (!value_to_fill)
		return;
	i++;
	for (j = 0 ; path_value[i]; i++, j++)
		value_to_fill[j] = path_value[i];
	if (value_to_fill[j - 1] != '/')
	{
		value_to_fill[j] = '/';
		value_to_fill[j + 1] = '\0';
	}
	else
		value_to_fill[j] = '\0';
	add_node_end(&path_head, value_to_fill);
}