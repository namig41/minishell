/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:41:05 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 15:44:55 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void 	current_path(void)
{
	char	buf[PATH_MAX + 1];

	getcwd(buf, PATH_MAX);
	ft_memdel((void **)&path);
	path = ft_strdup(buf);
}
