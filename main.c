#include "shell.h"
/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t id;
	int status = 0;
	char *cmd_path;
	char *envp[2];
	if (!argv || !*argv)
		return (status);
	if (check_for_builtin(argv))
		return (status);
	id = fork();
	if (id < 0)
	{
		perror("fork");
		return (1);
	}
	if (id == -1)
	{
		perror(argv[0]);
		free_tokens(argv);
		free_last_input();
	}
	if (id == 0)
	{
		envp[0] = get_path();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = find_in_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]);
			free_tokens(argv);
			free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}

/**
 * main - main function
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	char **args;
	int status;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
	do {
		input = get_input();
		if (!input || !*input)
			break;
		args = tokenize_input(input);
		if (!args || !*args)
		{
			free(input);
			free_tokens(args);
			continue;
		}
		status = execute(args);
		free(input);
		free_tokens(args);
		status = 1;
	} while (status);
	return("EXIT_SUCCESS");
}

