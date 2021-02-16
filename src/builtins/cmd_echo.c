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

static int check_env(char *var)
{
	if (var[0] == '$')
	{
        ft_putstr((char *)getenv(var + 1));
		return (1);
	}
	return (0);
}

static void put_echo(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i++;
			continue ;
		}
		ft_putchar(s[i]);
		i++;
	}
}

void 	cmd_echo(char **argv, char **env)
{
	size_t i;

	i = 1;
	while (argv[i])
	{
        if (!check_env(argv[i]))
			put_echo(argv[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
