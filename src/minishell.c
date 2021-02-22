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

void 	minishell(char **argv, char ***env)
{
	char *line;
	
    (void)argv;
	while (1)
	{
		current_path();
		if (get_next_line(STDIN_FILENO, &line) < 0)
		{
            clear_env(env);
			exit(1);
		}
        parse_line(line, env);
		ft_memdel((void **)&line);
	}
}
