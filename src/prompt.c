/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:41:05 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:44:55 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	offset_path(char **cur)
{
    int count;
    char *path;
    int i;

    i = 0;
    count = 3;
    path = *cur;
    while (path[i])
    {
       if (path[i] == '/')
           count--;
       if (!count)
           break;
        i++;
    }
    return i;
}

void	print_prompt(void)
{
    char buf[PATH_MAX + 1];
    char *path;
    int offs;

    path = getcwd(buf, PATH_MAX);
    offs = offset_path(&path);
    ft_putstr("\033[01;34m");
    ft_putstr("~ ");
    ft_putstr(path + offs);
    ft_putstr("➤\033[00m ");
}
