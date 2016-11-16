/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/16 18:22:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ent_filter(t_list **ent, int opts)
{
	if (!(opts & OPTS_LA))
		ft_lst_delif(ent, ".", &ft_lsdata_cmp0, &ft_ent_free);
}

void	ft_ent_sort(t_list **ent, int opts)
{
	int			(*ft_sort)();

	if (opts & OPTS_LT)
		ft_sort = &ft_lsdata_cmp_time;
	else
		ft_sort = &ft_lsdata_cmp_name;
	ft_lst_sort(ent, ft_sort);
	if (opts & OPTS_LR)
		ft_lst_reverse(ent);
}

void	ft_ent_print(t_list *ent, int *opts, t_lsdata *topdir, t_list *nextdir)
{
	if (*opts & OPTS_HEAD)
	{
		if (topdir)
			ft_printf("%s:\n", topdir->path);
	}
	else
		*opts |= OPTS_HEAD;
	if (ent)
	{
		if (*opts & OPTS_LL)
			ft_ls_long(ent, topdir);
		else
			ft_ls_short(ent);
	}
	if (nextdir || ((*opts & OPTS_UR) && ft_ent_has_dir(ent)))
		ft_putchar('\n');
}
