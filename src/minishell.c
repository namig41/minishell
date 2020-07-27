#include "minishell.h"

extern char *commands_str[];

static int search_command(char *command_name)
{
	size_t i;

	i = 0;
	while (commands_str[i])
	{
		if (ft_strequ(commands_str[i], command_name))
			return (1);
		i++;
	}
	return (0);
}

static void parse_command(char **argv, char **env)
{
	if (ft_strequ(argv[0], "env"))
		cmd_env(argv, env);
	else if (ft_strequ(argv[0], "cd"))
		cmd_cd(argv, env);
	else if (ft_strequ(argv[0], "exit"))
		cmd_exit(argv, env);
	else if (ft_strequ(argv[0], "pwd"))
		cmd_pwd(argv, env);
	else if (ft_strequ(argv[0], "help"))
		cmd_help(argv, env);
	else if (search_command(argv[0]))
		execute(argv, env);
	else 
	{
		ft_putstr(argv[0]);
		ft_putendl(": command not found");
	}
}

void 	minishell(char **argv, char **env)
{
	char *line;
	char **cmd;
	
	while (1)
	{
		ft_putstr("> ");
		if (get_next_line(STDIN_FILENO, &line) < 0)
			exit(1);
		cmd = ft_strsplit(line, ' ');
		parse_command(cmd, env);
		ft_memdel((void **)&line);
	}
}
