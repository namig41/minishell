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

void execute_command(char **argv, char **env)
{
    pid_t child_pid;

    child_pid = fork();
    (void)env;
    if (child_pid == 0)
    {
        if (execvp(argv[0], argv) == -1)
        {
            ft_putstr_fd(argv[0], STDERR_FILENO);
            ft_puterror(": command not found");
        }
    }
    else if (child_pid < 0)
        ft_puterror("failed to fork");
    else
        wait(&child_pid);
}

void search_command(char **argc, char ***env, int fd)
{
    int i;

    if ((i = search_cmd(argc[0], cmd)) != -1)
        cmd_func[i](argc, *env, fd);
    else if (cmd_setenv(argc, env, fd))
        ;
    else
        execute_command(argc, *env);
}

void process_command(char ****t_argc, char ***t_sep, char ***env)
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
        index = -1;
        fd = STDOUT_FILENO;
        if (v_sep[i])
        {
            index = search_cmd(v_sep[i], cmd_sep);

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
        search_command(argc[i], env, fd);
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
