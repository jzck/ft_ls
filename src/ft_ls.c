/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/21 14:44:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_dirs(t_list *dir, int opts)
{
	t_list		*dir_r;
	t_list		*ent;
	t_lsdata	*dirdata;
	t_list		*tmp;

	ft_ent_sort(&dir, opts);
	ent = NULL;
	while (dir)
	{
		dirdata = dir->content;
		tmp = dir;
		dir = dir->next;
		ft_lstdel(&ent, &ft_ent_free);
		ent = ft_dir_get_ents(dirdata);
		ft_ls_files(&ent, &dir, dirdata, &opts);
		ft_lstdelone(&tmp, &ft_ent_free);
		if (opts & OPTS_UR)
		{
			dir_r = ft_ent_get_dirs(&ent);
			ft_lst_merge(&dir_r, dir);
			dir = dir_r;
		}
	}
	ft_lstdel(&ent, &ft_ent_free);
}

void	ft_ls_files(t_list **ent, t_list **dir, t_lsdata *topdir, int *opts)
{
	if (ent)
	{
		ft_ent_filter(ent, *opts);
		ft_ent_sort(ent, *opts);
		ft_ent_print(*ent, opts, topdir, *dir);
	}
}
