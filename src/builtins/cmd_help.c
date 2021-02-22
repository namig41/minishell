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

void 	cmd_help(char **argv, char **env, int fd)
{
	size_t i;	

	i = 0;
    (void)argv;
    (void)env;
	while (cmd[i])
	{
        ft_putendl_fd(cmd[i], fd);
		i++;
	}
}

