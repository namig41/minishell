
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:40:51 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 11:24:52 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	signal_init(void)
{
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGSTOP, signal_handler);
    signal(SIGCONT, signal_handler);
}

void 	signal_handler(int sig)
{
    if (sig == SIGINT || sig == SIGQUIT)
        exit(1);
    else if (sig == SIGSTOP)
        g_signal_flag_run = 0;
    else if (sig == SIGCONT)
        g_signal_flag_run = 1;
}
