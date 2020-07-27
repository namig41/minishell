#include "minishell.h"

extern char *commands_str[];

void 	cmd_help(char **argv, char **env)
{
	size_t i;	

	i = 0;
	ft_putendl("Наберите название программы и её аргументы и нажмите enter.");
  	ft_putendl("Вот список втсроенных команд:");
	while (commands_str[i])	
	{
		ft_putendl(commands_str[i]);
		i++;
	}
}

