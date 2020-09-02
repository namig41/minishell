/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:15 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:44:00 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *path = NULL;

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

char *cmd_sep[] = {
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
