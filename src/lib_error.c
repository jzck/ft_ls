/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 14:04:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_option(char c)
{
	ft_dprintf(2, LS_MSG_ILLEGAL_OPT, c);
	ft_dprintf(2, LS_MSG_USAGE, LS_LEGAL_OPTS);
}

void	ft_error_access(char *s)
{
	/* ft_dprintf(2, LS_MSG_ACC_ERR, s); */
	/* ft_printf("strerror:%s\n", strerror(errno)); */
	ft_dprintf(2, "ls: ");
	perror(s);
}

void	ft_error_dir(char *s)
{
	/* ft_dprintf(2, LS_MSG_FILE_ERR, s); */
	/* ft_printf("strerror:%s\n", strerror(errno)); */
	ft_dprintf(2, "ls: ");
	if (*s)
		perror(s);
	else
	{
		perror("fts_open");
		exit(1);
	}
}
