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


/*--------------------------------- COMMANDS --------------------------*/

void ft_puterror(const char *s);

#endif
