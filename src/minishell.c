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

void 	minishell(char ***env)
{
	char *line;
	
    line = 0;
	while (1)
	{
        print_prompt();
        if (get_next_line(STDIN_FILENO, &line) < 0 || !line)
		{
            clear_env(env);
			exit(1);
		}
        parse_line(line, env);
        ft_memdel((void **)&line);
	}
}

int main(int argc, char *argv[], char *env[])
{
    (void)argc;
    (void)argv;
    signal(SIGINT, signal_handler);
    create_env(&env);
    minishell(&env);
    return (0);
}
