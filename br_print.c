#include "shell.h"
/**
 * br_puts - Prints a string to the standard output stream
 * @str: The string to print
 * Return: Void
 */
void custom_puts(char *str)
{
	size_t len;
	ssize_t result;

	len = br_strlen(str);
	result = write(STDOUT_FILENO, str, len);
	if (result == -1)
	{
		perror("write");
	}
}
