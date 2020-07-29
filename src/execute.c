#include "minishell.h"

void execute(char **argv, char **env)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror("permission dined");
		exit(0);
	}
	else if (child_pid < 0)
		perror("failed to fork");
	else
		wait(&child_pid);
}
