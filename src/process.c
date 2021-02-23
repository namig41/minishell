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

    (void)env;
    child_pid = fork();
    if (child_pid == 0)
    {
        if (execvp(argv[0], argv) == -1)
        {
            ft_puterror(argv[0]);
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
    char ***argc;
    char **v_sep;
    int fd;
    int first_command;
    int second_command;
    int index_command;

    first_command = 0;
    argc = *t_argc;
    v_sep = *t_sep;
    while (argc[first_command])
    {
        index_command = SEP_NOTHING;
        fd = STDOUT_FILENO;

        if (v_sep[first_command])
        {
            index_command = search_cmd(v_sep[first_command], cmd_sep);

            second_command = first_command + 1;

            if (index_command == SEP_REDIRECT_L_ADD || index_command == SEP_REDIRECT_L)
            {
                int tmp = first_command;

                first_command = second_command;
                second_command = tmp;
            }

            if (index_command == SEP_PIPE)
                ;
            else if (index_command == SEP_REDIRECT_R || index_command == SEP_REDIRECT_L)
            {
                fd = open(argc[second_command][0], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
            }
            else if (index_command == SEP_REDIRECT_R_ADD || index_command == SEP_REDIRECT_L_ADD)
            {
                fd = open(argc[second_command][0], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
            }
            else if (index_command == SEP_CONTINUE)
                index_command = SEP_NOTHING;
        }

        search_command(argc[first_command], env, fd);
        ft_strsplit_clear(argc[first_command]);

        if (index_command != SEP_NOTHING)
        {
            ft_strsplit_clear(argc[second_command]);
            if (index_command != SEP_REDIRECT_L_ADD && index_command != SEP_REDIRECT_L)
                first_command = second_command;
        }

        first_command++;
    }
    ft_memdel((void **)&argc);
    ft_strsplit_clear(v_sep);
}
