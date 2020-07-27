#include "minishell.h"

void execute(char **argv, char **env)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execvp(argv[0], argv);
		exit(0);
	}
	else if (child_pid < 0)
		exit(1);
	else
		wait(NULL);
}
