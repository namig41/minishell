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
	size_t i;

	i = 0;
	if (!env && !*env)
		return ;
	while ((*env)[i])
		ft_memdel((void **)&(*env)[i++]);
	ft_memdel((void **)&(*env));
}

void create_env(char ***env)
{
	char **e;
    int i;

    if (!(e = (char **)malloc(sizeof(char *) * (get_env_len(*env) + 1))))
	{
        ft_puterror("Allocation error");
		exit(1);
	}
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

    i = -1;
    if (!(e = (char **)malloc(sizeof(char *) * (get_env_len(*env) + 2))))
    {
        ft_puterror("Allocation error");
        exit(1);
    }
    while ((*env)[++i])
        e[i] = ft_strdup((*env)[i]);
    clear_env(env);
    e[i] = ft_strdup(new_env);
    e[i + 1] = 0;
    *env = e;
}
