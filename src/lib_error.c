/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/21 13:21:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_option(char c)
{
	ft_dprintf(2, LS_MSG_ILLEGAL_OPT, c);
	ft_dprintf(2, LS_MSG_USAGE, LS_LEGAL_OPTS);
}

void	ft_error_dir(char *s)
{
	ft_printf(LS_MSG_FILE_ERR, s);
}
