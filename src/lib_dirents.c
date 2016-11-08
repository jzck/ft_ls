/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:00:05 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 15:01:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ent_filter(t_list **ent, char *opts)
{
	if (!ft_strchr(opts, 'a'))
		ft_lst_delif(ent, ".", &ft_lsdata_cmp0, &ft_ent_free);
}

void	ft_ent_sort(t_list **ent, char *opts)
{
	int			(*ft_sort)();

	if (ft_strchr(opts, 't'))
		ft_sort = &ft_lsdata_cmp_time;
	else
		ft_sort = &ft_lsdata_cmp_name;
	ft_lst_sort(ent, ft_sort);
	if (ft_strchr(opts, 'r'))
		ft_lst_reverse(ent);
}

void	ft_ent_print(t_list *ent, char *opts, t_lsdata *topdir, t_list *nextdir)
{
	char	*opt;

	if (!(opt = ft_strchr(opts, '0')))
	{
		if (topdir)
			ft_printf("%s:\n", topdir->path);
	}
	else
		*opt = '.';
	if (ent)
	{
		if (ft_strchr(opts, 'l'))
			ft_ls_long(ent, topdir);
		else
			ft_ls_short(ent);
	}
	if (nextdir)
		ft_putendl("");
}

t_list	*ft_ent_get_dirs(t_list *ent)
{
	t_lsdata		*data;
	struct dirent	*dirent;
	t_list			*dir;
	t_list			*tmp;

	dir = NULL;
	while (ent)
	{
		data = ent->content;
		dirent = data->dirent;
		tmp = ent;
		ent = ent->next;
		if (dirent->d_type == DT_DIR
				&& ft_strcmp(dirent->d_name, ".")
				&& ft_strcmp(dirent->d_name, ".."))
		{
			tmp->next = NULL;
			ft_lsteadd(&dir, tmp);
		}
	}
	return (dir);
}
