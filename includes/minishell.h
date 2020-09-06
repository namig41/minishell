/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:06 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:59:02 by lcarmelo         ###   ########.fr       */
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

# define CLEAR_SCREEN "\033[?1049h\033[H"

/*
** ---------------------- MINISHELL ---------------------------------
*/


void 	minishell(char **argv, char **env);

/*
** ---------------------- PARSE ---------------------------------
*/

int 	belongs_set(char **set, char *el);

/*
** ---------------------- SYSCALL ---------------------------------
*/


void 	execute(char **argv, char **env);

/*
** ---------------------- COMMADS ---------------------------------
*/


void 	cmd_cd(char **argv, char **env);
void 	cmd_env(char **argv, char **env);
void 	cmd_pwd(char **argv, char **env);
void 	cmd_help(char **argv, char **env);
void 	cmd_exit(char **argv, char **env);
void 	cmd_clear(char **argv, char **env);
void 	cmd_echo(char **argv, char **env);


/*
** ---------------------- ERROR --j--------------------------------
*/

void 	ft_puterror(const char *s);

/*
** ---------------------- PATH ------------------------------------
*/

void 	current_path(void);

/*
** ---------------------- GLOBALS -------------------------------
*/

extern char *cmd[];
extern char *cmd_sep[];
extern void (*cmd_func[])(char **argv, char **env);

#endif
