#include "minishell.h"

void 	cmd_cd(char **argv, char **env)
{
	if (!argv[1])
	    ft_putendl("lsh: ожидается аргумент для \"cd\"\n");
	else
	{
		if (chdir(argv[1]) != 0)
			ft_putendl("Error");
	}
}
