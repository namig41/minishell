/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:06 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:59:02 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int  strequ(const char *s1, const char *s2)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s2);
    while (i < len)
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

int search_cmd(char *cmd_name, char **cmd_arr)
{
    int i;

    i = 0;
    while (cmd_arr[i])
    {
        if (strequ(cmd_name, cmd_arr[i]))
            return (i);
        i++;
    }
    return (-1);
}

int is_sep(char *line, char **cmd_sep)
{
    if (ft_isalnum(*line) || ft_isescape(*line))
        return -1;
    return (search_cmd(line, cmd_sep));
}
