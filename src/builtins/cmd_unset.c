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

void cmd_unset(char **argv, int fd)
{
	if (!argv[1] || argv[2])
	{
		ft_puterror("unset: arg error");
		return ;
	}

	(void)fd;
	erase_env(argv[1]);
}
