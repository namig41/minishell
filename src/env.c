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

char *get_env(const char *env_name)
{
	t_list *l_tmp;
	size_t len;

	l_tmp = l_env;
	while (l_tmp)
	{
		len = ft_memchr(l_tmp->data, '=', l_tmp->size) - l_tmp->data;
		if (!ft_memcmp(l_tmp->data, (void *)env_name, len))
			return (char *)l_tmp->data + len + 1;
		l_tmp = l_tmp->next;
	}
	return (NULL);
}

void erase_env(const char *env_name)
{
	size_t len;
	t_list *cur_node;
	t_list *prev_node;

	prev_node = NULL;
	cur_node = l_env;
	while (cur_node)
	{
		len = ft_memchr(cur_node->data, '=', cur_node->size) - cur_node->data;
		if (!ft_memcmp(cur_node->data, (void *)env_name, len))
		{
			if (prev_node)
				prev_node->next = cur_node->next;
			else
				l_env = l_env->next;
			ft_memdel(&cur_node->data);
			ft_memdel((void **)&cur_node);
			return ;
		}
		prev_node = cur_node;
		cur_node = cur_node->next;
	}
}

void clear_env(void)
{
	list_destroy(&l_env);
}

void add_new_env(char *new_env)
{
	list_push_front(&l_env, (void *)new_env, ft_strlen(new_env));
}

void init_env(char **env)
{
	size_t i;
	char *var_env;

	i = 0;
	while (env[i])
	{
		var_env = ft_strdup(env[i]);
		list_push_front(&l_env, (void *)var_env, ft_strlen(var_env));
		ft_memdel((void **)&var_env);
		i++;
	}
}
