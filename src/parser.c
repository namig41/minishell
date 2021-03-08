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

void allocate_memory(char *line, char ****argv, char ***v_sep)
{
    size_t i;
    size_t sep_count;

    i = 0;
    sep_count = 1;
    while (line[i])
    {
        if (is_sep(line + i, cmd_sep) != -1)
           sep_count++;
        i++;
    }

    if (!(*argv = (char ***)ft_memalloc(sizeof(char ***) * (sep_count + 1))))
        return ;

    if (!(*v_sep = (char **)ft_memalloc(sizeof(char **) * sep_count)))
        return ;

    (*v_sep)[sep_count - 1] = 0;
    (*argv)[sep_count] = 0;
}

void parse_command(char *line, char ****t_argv, char ***t_sep)
{
    size_t i;
    size_t j;
    int st;
    int index;
    char ***argv;
    char **v_sep;

    i = 0;
    j = 0;
    st = 0;
    argv = *t_argv;
    v_sep = *t_sep;
    while (line[i])
    {
        if ((index = is_sep(line + i, cmd_sep)) != -1)
        {
            v_sep[j] = ft_strdup(cmd_sep[index]);
            line[i] = 0;
            argv[j] = ft_strsplit(line + st, ' ');
            i += ft_strlen(v_sep[j]) - 1;
            st = i + 1;
            j++;
        }
        i++;
    }

    argv[j] = ft_strsplit(line + st, ' ');
}

void parse_line(char *line)
{
    char ***argv;
    char **v_sep;

    allocate_memory(line, &argv, &v_sep);
    parse_command(line, &argv, &v_sep);
	process_command(&argv, &v_sep);
}
