#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>

#include "libft.h"
#include "vector.h"

void minishell(char **argv, char **env);


void execute(char **argv, char **env);


void cmd_env(char **argv, char **env);
void cmd_pwd(char **argv, char **env);
void cmd_exit(char **argv, char **env);

#endif
