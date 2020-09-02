/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:06 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 14:24:07 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>

# include "libft.h"
# include "vector.h"
# include "get_next_line.h"

/*--------------------------------- MINISHELL -----------------------*/

void 	minishell(char **argv, char **env);

/*---------------------------------- PARSE ---------------------------*/

char 	***parse_line(char *line);
int 	belongs_set(char **set, char *el);

/*---------------------------------- SYSCALL -------------------------*/

void 	execute(char **argv, char **env);

/*--------------------------------- COMMANDS --------------------------*/

void 	cmd_cd(char **argv, char **env);
void 	cmd_env(char **argv, char **env);
void 	cmd_pwd(char **argv, char **env);
void 	cmd_help(char **argv, char **env);
void 	cmd_exit(char **argv, char **env);


/*--------------------------------- ERRORS --------------------------*/

void ft_puterror(const char *s);

/*--------------------------------- GLOBALS --------------------------*/

extern char *cmd[];
extern char *m_cmd[];
extern void (*cmd_func[])(char **argv, char **env);

#endif
