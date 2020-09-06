/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:26 by lcarmelo          #+#    #+#             */
/*                                                                            */
/*   Updated: 2020/09/02 13:53:52 by lcarmelo         ###   ########.fr       */
/* ************************************************************************** */

#include "minishell.h"

static int search_command(char **cmd, char **argc)
{
	int index;
	size_t i;

	i = 0;
	while (argc[i])
	{
		index = 0;
		while (cmd[index])
		{
			if (ft_strequ(cmd[index], argc[i]))
				return (index);
			index++;
		}
		i++;
	}
	return (-1);
}

static void parse_command(char **argc, char **env)
{
	int index;

	if ((index = search_command(cmd, argc)) != -1)
		cmd_func[index](argc, env);
	else 
		execute(argc, env);
}

void 	minishell(char **argv, char **env)
{
	char *line;
	char **cmd;
	
	current_path();
	while (1)
	{
		ft_putstr(path);
		ft_putstr(">");
		if (get_next_line(STDIN_FILENO, &line) < 0)
			exit(1);
		cmd = ft_strsplit(line, ' ');
		parse_command(cmd, env);
		ft_strsplit_clear(cmd);
		ft_memdel((void **)&line);
	}
}
