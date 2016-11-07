/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 15:30:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_option(char c)
{
	ft_printf("warning option '%c' is unsupported\n", c);
}

void	ft_error_dir(char *s)
{
	ft_printf("ls: %s: no such file or directory\n", s);
}
