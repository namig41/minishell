#include "minishell.h"

char *m_cmd[] = {
	"cd",
	"env", 
	"help",
	"pwd",
	"exit",
  	NULL
};

char *cmd[] = {
	"ls",
	"man",
	"clear",
	NULL
};

char *shell_sep[] = {
	"|",
	">",
	">>",
	"<",
	"<<",
	"||",
	"&&",
	"&",
	NULL
};

void (*cmd_func[])(char **args, char **env) = {
	&cmd_cd,
	&cmd_env,
	&cmd_help,
	&cmd_pwd,
	&cmd_exit,
	NULL
};
