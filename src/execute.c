/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:50:21 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 13:50:21 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute(char **argv, char **env)
{
	pid_t child_pid;

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
