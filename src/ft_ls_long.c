/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/21 14:25:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_long(t_list *ent, t_lsdata *topdir)
{
	t_pads	pads;

	if (topdir)
		ft_ls_long_total(ent);
	if (ft_ls_long_pads(ent, &pads))
		return (1);
	while (ent)
	{
		if (ft_ls_long_print(ent, pads))
			return (1);
		ent = ent->next;
	}
	return (0);
}

int		ft_ls_long_print(t_list *ent, t_pads pads)
{
	t_lsdata		*data;
	struct stat		stat;
	struct dirent	*dirent;

	data = ent->content;
	stat = data->stat;
	dirent = data->dirent;
	ent = ent->next;
	ft_ls_long_type(stat.st_mode);
	ft_ls_long_rights(stat.st_mode);
	if (ft_ls_long_xattr(stat.st_mode, data->path))
		return (1);
	if (ft_ls_long_middle(&stat, &pads))
		return (1);
	ft_ls_long_date(&stat);
	ft_printf(" ");
	ft_lsdata_filename(data);
	if (ft_ls_long_lnk(data))
		return (1);
	return (0);
}
