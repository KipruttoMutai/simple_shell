#include "shell.h"
/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_for_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!br_strcmp(args[0], "exit"))
		br_exit(args);
	else if (!br_strcmp(args[0], "env"))
		br_env();
	else if (!br_strcmp(args[0], "setenv"))
		br_setenv(args);
	else if (!br_strcmp(args[0], "unsetenv"))
		br_unsetenv(args);
	else if (!br_strcmp(args[0], "help"))
		br_help();
	else if (!br_strcmp(args[0], "cd"))
		br_cd(args);
	else if (!br_strcmp(args[0], "clear"))
		br_clear(args);
	else
		return (0);
	return (1);
}

/**
 * br_exit - Exit the shell.
 * @args: Arguments.
 * Return: Nothing.
 */
void br_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = br_atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(status);
}

/**
 * br_env - Prints all the environment variables.
 * Return: void.
 */
int br_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		br_puts(environ[i]);
		br_putchar('\n');
	}

	return (0);
}

/**
 * br_cd - changes the current working directory of the shell
 * @args: array of arguments
 */
void br_cd(char **args)
{
	char *dir = args[1];
	int ret;

	if (dir == NULL)
	{
		dir = br_getenv("HOME");
		if (dir == NULL)
		{
			br_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}

/**
 * br_clear - clears the terminal screen.
 * @args: an array of arguments
 * Return: 1 to continue executing,0 to exit
*/
int br_clear(char **args)
{
	(void)args;
	br_puts("\033[2J\033[H");
	return (1);
}
