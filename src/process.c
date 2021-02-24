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
            ft_putstr_fd(argv[0], STDERR_FILENO);
            ft_puterror(": command not found");
        }
    }
    else if (child_pid < 0)
        ft_puterror("failed to fork");
    else
        wait(&child_pid);
}

void execute_command_with_pipe(char **argv1, char **argv2, char **env)
{
    int fd[2];
    pid_t child_pid;

    (void)env;

    if (pipe(fd) == -1)
    {
        ft_puterror("pipe failed");
        return ;
    }

    child_pid = fork();
    if (child_pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        if (execvp(argv1[0], argv1) == -1)
        {
            ft_putstr_fd(argv1[0], STDERR_FILENO);
            ft_puterror(": command not found");
        }
        exit(1);
    }
    else if (child_pid < 0)
        ft_puterror("failed to fork");
    else
    {
        child_pid = fork();

        if (child_pid == 0)
        {
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);

            if (execvp(argv2[0], argv2) == -1)
            {
                ft_putstr_fd(argv1[0], STDERR_FILENO);
                ft_puterror(": command not found");
            }
            else if (child_pid < 0)
                ft_puterror("failed to fork");
            else
                exit(1);
        }

        close(fd[0]);
        close(fd[1]);

        int status;
        waitpid(child_pid, &status, 0);
    }
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
    int fd;
    int first_command;
    int second_command;
    int index_command;
    char ***argc;
    char **v_sep;

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
            {
                execute_command_with_pipe(argc[first_command], argc[second_command], *env);
                ft_strsplit_clear(argc[first_command]);
                ft_strsplit_clear(argc[second_command]);

                first_command = second_command + 1;
                continue ;
            }
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
