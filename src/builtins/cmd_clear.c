#include "minishell.h"

void 	cmd_clear(char **argv, char **env)
{
	(void)argv;
	(void)env;
	ft_putstr(CLEAR_SCREEN);
}
