#include "shell.h"

/**
 * prompt - prints prompt to stdin
 * Return: -1 on failure greater than 0 on success
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", br_strlen("$ "));
}
