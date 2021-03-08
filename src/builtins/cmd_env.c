/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:56:18 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:28:54 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	cmd_env(char **argv, int fd)
{
	t_list *l_tmp;

    (void)argv;
	l_tmp = l_env;
	while (l_tmp)
    {
		ft_putendl_fd((char *)l_tmp->data, fd);
		l_tmp = l_tmp->next;
    }
}
