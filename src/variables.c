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

char *cmd[] = {
	"cd",
	"env", 
	"help",
	"pwd",
	"clear",
	"echo",
    "eval",
	"unset",
	"exit",
  	NULL
};

void (*cmd_func[])(char **argv, int fd) = {
    &cmd_cd,
    &cmd_env,
    &cmd_help,
    &cmd_pwd,
    &cmd_clear,
    &cmd_echo,
    &cmd_eval,
	&cmd_unset,
    &cmd_exit,
    NULL
};

char *cmd_sep[] = {
	"|",
    ">>",
    "<<",
    ">",
    "<",
    ";",
    NULL
};

volatile sig_atomic_t g_signal_flag_run = 1;
