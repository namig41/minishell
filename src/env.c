
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

	i = -1;
	while ((*env)[++i])
		;
	if (!(e = (char **)malloc(sizeof(char *) * (i + 1))))
	{
		ft_puterror("alloc error");
		exit(1);
	}
	i = -1;
	while ((*env)[++i])
		e[i] = ft_strdup((*env)[i]);
	e[i] = 0;
	*env = e;
}

