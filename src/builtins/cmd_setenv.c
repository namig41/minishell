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

int 	cmd_setenv(char **argv, char ***env)
{
    int i;
    int assig;

    i = 0;
    assig = -1;
    if (!argv[0] || argv[1])
        return 0;
    else
    {
        while (argv[0][i])
        {
            if (argv[0][i] == '=')
            {
                if (assig == -1)
                    assig = i;
                else
                    return 0;
            }
            i++;
        }
        if (assig == 0 || assig == i)
            return 0;
        add_new_env(env, argv[0]);
    }
    return 1;
}
