#include "minishell.h"

void 	cmd_pwd(char **argv, char **env)
{
	char *pwd;

	pwd = getenv("PWD");
	ft_putendl(pwd);
}
