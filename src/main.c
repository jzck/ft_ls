/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 17:42:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_list		*dir;
	t_list		*ent;
	char		*opts;

	dir = NULL;
	ent = NULL;
	opts = ft_parse_ls(ac, av, &dir, &ent);
	ft_ls_files(ent, dir, opts);
	ft_ls_dirs(dir, opts);
	return (errno);
}
