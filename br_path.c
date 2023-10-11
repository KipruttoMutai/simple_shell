#include "shell.h"
/**
 * get_path - Returns the value of the PATH enviroment variable.
 * Return: Pointer to the value of $PATH.
 */
char *get_path(void)
{
	return (br_getenv("PATH"));
}

/**
 * find_in_path - Looks for a command in each directory specified in the PATH
 * environment variable
 * @command: Pointer to the `command` string to look for.
 * Return: Pointer to a string containing the full path
 * or NULL if it is not found
 */
char *find_in_path(char *command)
{
	char *full_path;
	char *path;
	char **dirs;
	struct stat st;
	char buf[PATH_MAX_LENGTH];

	path = get_path();
	if (!path)
		return (NULL);
	dirs = tokenize(path, PATH_SEPARATOR);
	if (!dirs)
	{
		free(path);
		return (NULL);
	}
	full_path = NULL;
	for (int i = 0; dirs[i] != NULL; i++)
	{
		snprintf(buf, PATH_MAX_LENGTH, "%s/%s", dirs[i], command);
		if (stat(buf, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			full_path = br_strdup(buf);
			break;
		}
	}
	free_tokens(dirs);
	free(path);
	return (full_path);
}
