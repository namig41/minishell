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

void 	minishell(void)
{
	char *line;
	
    line = 0;
    while (g_signal_flag_run)
	{
        print_prompt();
        if (get_next_line(STDIN_FILENO, &line) < 0 || !line)
			cmd_exit(0, 0);
		parse_line(line);
        ft_memdel((void **)&line);
	}
}

int main(int argc, char *argv[], char *env[])
{
    (void)argc;
    (void)argv;
	signal_init();
	init_env(env);
	minishell();
    return (0);
}
