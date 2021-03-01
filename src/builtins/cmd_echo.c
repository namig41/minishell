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

static int check_env(char *var, int fd)
{
	if (var[0] == '$')
	{
        ft_putstr_fd(getenv(var + 1), fd);
		return (1);
	}
	return (0);
}

static void put_echo(const char *s, int fd)
{
	size_t i;

	i = 0;
	while (s[i])
	{
        if (s[i] != 34 && s[i] != 39)
            ft_putchar_fd(s[i], fd);
		i++;
	}
}

void 	cmd_echo(char **argv, char **env, int fd)
{
	size_t i;

	i = 1;
    (void)env;
	while (argv[i])
	{
        if (!check_env(argv[i], fd))
            put_echo(argv[i], fd);
        if (argv[i + 1])
            ft_putchar_fd(' ', fd);
		i++;
	}
    ft_putchar_fd('\n', fd);
}
