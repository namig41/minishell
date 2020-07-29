#include "minishell.h"
#include <stdio.h>

extern char *cmd[];
extern char *m_cmd[];
extern void (*cmd_func[])(char **argv, char **env);


static int search_command(char **cmd, char ***argc)
{
	int index;
	size_t i;

	i = 0;
	while (argc[i])
	{
		if ((index = belongs_set(cmd, argc[i][0])) != -1)
			return (index);
		i++;
	}
	return (-1);
}

static void parse_command(char ***argc, char **env)
{
	size_t i;
	int index;

	i = 0;
	if ((index = search_command(m_cmd, argc)) != -1)
		cmd_func[index](argc[0], env);
	else if (search_command(cmd, argc) != -1)
		execute(argc[0], env);
	else 
	{
		ft_puterror(argc[i][0]);
		ft_puterror(": command not found\n");
	}
}

void 	minishell(char **argv, char **env)
{
	char *line;
	char ***cmd;
	
	while (1)
	{
		ft_putstr("> ");
		if (get_next_line(STDIN_FILENO, &line) < 0)
			exit(1);
		cmd = parse_line(line);
		parse_command(cmd, env);
		ft_memdel((void **)&line);
	}
}
