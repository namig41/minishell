/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:49:55 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 13:50:01 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int get_env_len(char **env)
{
    int len;

    len = -1;
    while (env[++len])
        ;
    return len;
}

void clear_env(char ***env)
{
    ft_strsplit_clear(*env);
}

void create_env(char ***env)
{
	char **e;
    int i;

    if (!(e = (char **)malloc(sizeof(char *) * (get_env_len(*env) + 1))))
        return ;

	i = -1;
	while ((*env)[++i])
		e[i] = ft_strdup((*env)[i]);

	e[i] = 0;
	*env = e;
}

void add_new_env(char ***env, char *new_env)
{
    char **e;
    int i;

    if (!(e = (char **)malloc(sizeof(char *) * (get_env_len(*env) + 2))))
        return ;

    i = -1;
    while ((*env)[++i])
        e[i] = ft_strdup((*env)[i]);

    clear_env(env);
    e[i] = ft_strdup(new_env);
    e[i + 1] = 0;
    *env = e;
}
