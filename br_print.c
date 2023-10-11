#include "shell.h"
/**
 * br_puts - Prints a string to the standard output stream
 * @str: The string to print
 * Return: Void
 */
void br_puts(char *str)
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

/**
 *br_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int br_putchar(char c)
{
	return (write(1, &c, 1));
}
