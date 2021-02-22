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

void 	cmd_cd(char **argv, char **env)
{
    (void)env;
	if (!argv[1])
        ft_puterror("Not path");
	else
	{
		if (chdir(argv[1]) != 0)
            ft_puterror("Path don't found");
	}
}
