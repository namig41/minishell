#include "minishell.h"

void 	cmd_exit(char **argc, char **env)
{
	(void)argc;
	(void)env;
	exit(0);
}
