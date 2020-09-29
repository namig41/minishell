
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

void create_env(char ***env)
{
	char **e;
	int i;

	i = -1;
	while ((*env)[++i])
		;
	e = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while ((*env)[++i])
		e[i] = ft_strdup((*env)[i]);
	e[i] = 0;
	*env = e;
}

void clear_env(char **env)
{
	ft_strsplit_clear(env);
}
