#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigint(int sig)
{
	(void) sig;
	br_putchar('\n');
	prompt();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigquit(int sig)
{
	(void) sig;
	perror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP
 * @sig: Signal number
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
	(void) sig;
	br_puts("\n");
	prompt();
}
