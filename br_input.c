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
		read_result = br_getline(&input, &input_size, stdin);
		if (read_result == -1)
		{
			free(input);
			/*br_puts("\n");*/
			return (NULL);
		}
		input[read_result - 1] = '\0';
	} while (input[0] == '\0' || isspace(input[0]));
	last_input = input;
	return (input);
}
/**
 * br_getline - Read a line of input from a file stream.
 * @lineptr: A pointer to a char pointer where the line will be stored.
 * @n: A pointer to the initial and final size of the buffer.
 * @stream: The input file stream.
 * Return: The number of characters read, or -1 for error or end of file.
 */
ssize_t br_getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t read_size, i = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	read_size = *n;
	while (1)
	{
		if (i >= read_size)
		{
			read_size *= 2;
			new_lineptr = (char *)realloc(*lineptr, read_size);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
		}
		c = fgetc(stream);
		if (c == EOF)
			break;
		(*lineptr)[i] = (char)c;
		i++;
		if (c == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	if (i == 0 && c == EOF)
		return (-1);
	return (i);
}

/**
 * tokenize - splits an array string into tokens using a delimiter.
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 * Return: an array of pointers to the tokens.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);

		ret[i] = malloc(br_strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		br_strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
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
