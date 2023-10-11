#include "shell.h"
static char *last_input;
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
	last_input = input;
	return (input);
}

/**
 * tokenize_input - splits a user input string into tokens
 * @input: the user input string to be tokenized
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *input_copy = NULL;

	input_copy = br_strdup(input);
	if (input_copy == NULL)
	{
		br_puts("Malloc error");
		exit(EXIT_FAILURE);
	}
	tokens = tokenize(input_copy, " \t\r\n\a");
	free(input_copy);
	return (tokens);
}
