#include "shell.h"

/**
 * br_getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *br_getenv(const char *name)
{
	char **env;
	size_t name_len = br_strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (br_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}

/**
 * br_setenv - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 * Return: Nothing
 */
int br_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * br_unsetenv - Unset an environment variable
 * @args: Arguments name of the environment variable
 * Return: Nothing
 */
int br_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		perror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}

/**
 * br_help - displays help information for built-in commands
 */
void br_help(void)
{
	br_puts("\nShell Version 1.0.0\n\n");
	br_puts("Usage: ./hsh\n\n");
	br_puts("Shell built-in commands:\n\n");
	br_puts("help\t\tDisplay this help information\n\n");
	br_puts("cd [dir]\tChange the current working directory\n\n");
	br_puts("env\t\tDisplay the environment variables\n\n");
	br_puts("setenv\t\tSet an environment variable\n\n");
	br_puts("unsetenv\tUnset an environment variable\n\n");
	br_puts("exit\t\tExit the shell\n\n");
}
