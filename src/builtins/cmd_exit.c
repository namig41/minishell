#include "minishell.h"

void 	cmd_exit(char **argc, char **env)
{
	(void)argc;
	(void)env;
	clear_env(env);
	exit(0);
}
