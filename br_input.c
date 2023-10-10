#include "shell.h"
/**
 * get_input - Read the line of input from the user.
 * Return: Pointer to a buffer containing the user's input.
 */
char *get_input(void)
{
	/*char *previous_input;*/
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_result;

	do {
		prompt();
		read_result = getline(&input, &input_size, stdin);
		if (read_result == -1)
		{
			free(input);
			br_puts("\n");
			return (NULL);
		}
		input[read_result - 1] = '\0';
	} while (input[0] == '\0' || isspace(input[0]));
	/*previous_input = input;*/
	return (input);
}
