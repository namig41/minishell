/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:56:28 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:34:16 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	cmd_pwd(char **argv, char **env, int fd)
{
	char	buf[PATH_MAX + 1];

    (void)argv;
    (void)env;
    ft_putendl_fd(getcwd(buf, PATH_MAX), fd);
}
