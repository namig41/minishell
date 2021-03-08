/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:56:09 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:45:27 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	cmd_cd(char **argv, int fd)
{
    char *home_path;
    char *new_path;

    (void)fd;
	home_path = get_env("HOME");
    if (!argv[1])
        new_path = home_path;
    else
    {
        if (ft_strequ(argv[1], "--"))
            new_path = home_path;
        else if (argv[1][0] == '-' && !argv[1][2])
			new_path = get_env("OLDPWD");
        else
            new_path = argv[1];
    }

    if (chdir(new_path))
    {
        ft_putstr("cd: ");
        if (access(new_path, F_OK) == -1)
            ft_putstr("no such file or directory: ");
        else if (access(new_path, R_OK) == -1)
            ft_putstr("permission denied: ");
        else
            ft_putstr("not a directory: ");
        ft_putendl(argv[1]);
    }
}
