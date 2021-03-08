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
# include <fcntl.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include "libft.h"
# include "vector.h"
# include "get_next_line.h"
# include "stack.h"
# include "list.h"

# define CLEAR_SCREEN "\033[?1049h\033[H"

typedef enum e_sep
{
	SEP_NOTHING = -1,
	SEP_PIPE,
	SEP_REDIRECT_R_ADD,
	SEP_REDIRECT_L_ADD,
	SEP_REDIRECT_R,
	SEP_REDIRECT_L,
	SEP_CONTINUE
}           t_sep;

/*
** ---------------------- MINISHELL ---------------------------------
*/

void 	minishell(void);

/*
** ---------------------- ENV ---------------------------------------
*/

void	init_env(char **env);
void	add_new_env(char *new_env);
void 	clear_env(void);
char	*get_env(const char *env_name);
void 	erase_env(const char *env_name);

/*
** ---------------------- PROCESS COMMAND ---------------------------
*/

void    execute_command(char **argv, int fd);
void 	search_command(char **argv, int fd);
void 	process_command(char ****t_argv, char ***t_sep);
void	execute_command_with_pipe(char **argv1, char **argv2);

/*
** ---------------------- COMMANDS ---------------------------------
*/

void 	cmd_cd(char **argv, int fd);
void 	cmd_env(char **argv, int fd);
void 	cmd_pwd(char **argv, int fd);
void 	cmd_help(char **argv, int fd);
void 	cmd_exit(char **argv, int fd);
void 	cmd_clear(char **argv, int fd);
void 	cmd_echo(char **argv, int fd);
void	cmd_eval(char **argv, int fd);
void 	cmd_unset(char **argv, int fd);
int 	cmd_setenv(char **argv, int fd);

/*
** ---------------------- PROMPT ----------------------------------
*/

void 	print_prompt(void);

/*
** ---------------------- PARSE -----------------------------------
*/

void	parse_line(char *line);

/*
** ---------------------- SIGNALS -----------------------------------
*/

void 	signal_init(void);
void 	signal_handler(int sig);

/*
** ---------------------- UTILITIES -------------------------------
*/

int 	strequ(const char *s1, const char *s2);
int 	search_cmd(char *cmd_name, char **cmd_arr);
int 	is_sep(char *line, char **cmd_sep);

/*
** ---------------------- GLOBALS -------------------------------
*/

t_list *l_env;

extern char *cmd[];
extern char *cmd_sep[];
extern void (*cmd_func[])(char **argv, int fd);
extern volatile sig_atomic_t g_signal_flag_run;

#endif
