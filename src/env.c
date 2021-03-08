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

void clear_env(void)
{
	list_destroy(&l_env);
}

void add_new_env(char *new_env)
{
	list_push_back(&l_env, (void *)new_env, ft_strlen(new_env));
}

void init_env(char **env)
{
	size_t i;
	char *var_env;

	i = 0;
	while (env[i])
	{
		var_env = ft_strdup(env[i]);
		list_push_back(&l_env, (void *)var_env, ft_strlen(var_env));
		ft_memdel((void **)&var_env);
		i++;
	}
}
