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

static int  strequ(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

static int search(char *cmd_name, char **cmd_arr)
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

static void execute_command(char **argc, char ***env, int fd)
{
    int i;

    if ((i = search(argc[0], cmd)) != -1)
        cmd_func[i](argc, *env, fd);
    else if (cmd_setenv(argc, env, fd))
        ;
    else
        execute(argc, *env);
}

static int search_sep(char *line, char **cmd_sep)
{
    if (ft_isalnum(*line) || ft_isescape(*line))
        return -1;
    return (search(line, cmd_sep));
}

static int allocate_memory(char *line, char ****argc, char ***v_sep)
{
    size_t i;
    size_t sep_count;

    i = 0;
    sep_count = 1;
    while (line[i])
    {
        if (search_sep(line + i, cmd_sep) != -1)
           sep_count++;
        i++;
    }

    if (!(*argc = (char ***)ft_memalloc(sizeof(char ***) * (sep_count + 1))))
        return 0;

    if (!(*v_sep = (char **)ft_memalloc(sizeof(char **) * sep_count)))
        return 0;

    (*v_sep)[sep_count - 1] = 0;
    (*argc)[sep_count] = 0;

    return 1;
}

static void process_command(char ****t_argc, char ***t_sep, char ***env)
{
    size_t i;
    int index;
    char ***argc;
    char **v_sep;
    int fd;

    i = 0;
    index = 0;
    argc = *t_argc;
    v_sep = *t_sep;
    while (argc[i])
    {
        fd = 1;
        index = -1;
        if (v_sep[i])
        {
            index = search(v_sep[i], cmd_sep);

            if (index == SEP_PIPE)
                ;
            else if (index == SEP_REDIRECT)
            {
                fd = open(argc[i + 1][0], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
            }
            else if (index == SEP_REDIRECT_ADD)
            {
                fd = open(argc[i + 1][0], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
            }
            else if (index == SEP_CONTINUE)
                ;
        }
        execute_command(argc[i], env, fd);
        ft_strsplit_clear(argc[i]);
        if (index != -1)
        {
            i++;
            ft_strsplit_clear(argc[i]);
        }
        i++;
    }
    ft_memdel((void **)&argc);
    ft_strsplit_clear(v_sep);
}

// command_name arg arg sep command_name arg arg

static void parse_command(char *line, char ****t_argc, char ***t_sep)
{
    size_t i;
    size_t j;
    int st;
    int index;
    char ***argc;
    char **v_sep;

    i = 0;
    j = 0;
    st = 0;
    argc = *t_argc;
    v_sep = *t_sep;
    while (line[i])
    {
        if ((index = search_sep(line + i, cmd_sep)) != -1)
        {
            v_sep[j] = ft_strdup(cmd_sep[index]);
            line[i] = 0;
            argc[j] = ft_strsplit(line + st, ' ');
            i += ft_strlen(v_sep[j]) - 1;
            st = i + 1;
            j++;
        }
        i++;
    }

    argc[j] = ft_strsplit(line + st, ' ');
}

void parse_line(char *line, char ***env)
{
    char ***argc;
    char **v_sep;

    if (!allocate_memory(line, &argc, &v_sep))
        return ;

    parse_command(line, &argc, &v_sep);
    process_command(&argc, &v_sep, env);
}
