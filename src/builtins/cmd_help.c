#include "minishell.h"

extern char *m_cmd[];

void 	cmd_help(char **argv, char **env)
{
	size_t i;	

	i = 0;
	ft_putendl("Наберите название программы и её аргументы и нажмите enter.");
  	ft_putendl("Вот список втсроенных команд:");
	while (m_cmd[i])	
	{
		ft_putendl(m_cmd[i]);
		i++;
	}
}

