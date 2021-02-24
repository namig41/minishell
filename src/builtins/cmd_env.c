/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:56:18 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:28:54 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	cmd_env(char **argv, char **env, int fd)
{
	int i;

    i = -1;
    (void)argv;
    (void)env;
	while (env[++i])
        ft_putendl_fd(env[i], fd);
}
