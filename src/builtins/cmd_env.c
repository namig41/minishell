#include "minishell.h"

void 	cmd_env(char **argv, char **env)
{
	size_t i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
