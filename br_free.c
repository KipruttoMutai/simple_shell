#include "shell.h"
static char *last_input;
/**
 * free_tokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 * Return: void.
 */
void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}

/**
 * free_last_input - frees the last user input
 **/
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
