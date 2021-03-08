/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:55:20 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:31:09 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void print_header(int fd)
{
    ft_putchar_fd('\n', fd);
    ft_putendl_fd(",-.-.o     o     |         |    |    ", fd);
    ft_putendl_fd("| | |.,---..,---.|---.,---.|    |    ", fd);
    ft_putendl_fd("| | |||   ||`---.|   ||---'|    |    ", fd);
    ft_putendl_fd("` ' '``   '``---'`   '`---'`---'`---'", fd);

    ft_putendl_fd("Type program names and arguments, and hit enter.", fd);
    ft_putendl_fd("The following are built in:", fd);
}

void 	cmd_help(char **argv, int fd)
{
	size_t i;	

	i = 0;
    (void)argv;
    print_header(fd);
	while (cmd[i])
	{
		ft_putnbr_fd(i + 1, fd);
		ft_putstr_fd(". ", fd);
        ft_putendl_fd(cmd[i], fd);
		i++;
	}
}

