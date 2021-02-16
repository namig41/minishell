/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:49:55 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 13:50:01 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int search_command(char **cmd, char **argc)
{
    int j;
    size_t i;

	i = 0;
	while (argc[i])
	{
        j = 0;
        while (cmd[j])
		{
            if (ft_strequ(cmd[j], argc[i]))
                return (j);
            j++;
		}
		i++;
	}
	return (-1);
}

static void parse_command(char **argc, char ***env)
{
    int i;

    if ((i = search_command(cmd, argc)) != -1)
        cmd_func[i](argc, *env);
    else if (cmd_setenv(argc, env))
        ;
	else 
        execute(argc, *env);
}

void 	minishell(char **argv, char ***env)
{
	char *line;
	char **cmd;
	
    (void)argv;
	while (1)
	{
		current_path();
		if (get_next_line(STDIN_FILENO, &line) < 0)
		{
            clear_env(env);
			exit(1);
		}
		cmd = ft_strsplit(line, ' ');
		parse_command(cmd, env);
		ft_strsplit_clear(cmd);
		ft_memdel((void **)&line);
	}
}
