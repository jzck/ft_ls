/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_lsdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 18:49:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lsdata_filename(t_lsdata *data, t_lsdata *topdir, int opts)
{
	struct dirent	*dirent;

	dirent = data->dirent;
	if (data->path)
		ft_printf("%s", topdir ? ft_path_notdir(data->path) : data->path);
	else if (dirent && *dirent->d_name)
		ft_printf("%s", dirent->d_name);
	else
		ft_printf("noname!");
	if (opts & OPTS_LP && S_ISDIR(data->stat.st_mode))
		ft_putchar('/');
}

int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2)
{
	return (ft_strcmp(dat1->path, dat2->path));
}

int		ft_lsdata_cmp0(t_lsdata *data, char *dataref)
{
	char	*filename;

	if (data->path)
		filename = ft_path_notdir(data->path);
	else
		filename = data->dirent->d_name;
	return (*filename != *dataref);
}

int		ft_lsdata_cmpA(t_lsdata *data, char *dataref)
{
	char	*filename;

	(void)dataref;
	if (data->path)
		filename = ft_path_notdir(data->path);
	else
		filename = data->dirent->d_name;
	if (!ft_strcmp(filename, ".") || !ft_strcmp(filename, ".."))
		return (0);
	return (1);
}

int		ft_lsdata_cmp_size(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_size - dat1->stat.st_size)
		return (dat2->stat.st_size - dat1->stat.st_size);
	else
		return (ft_strcmp(dat1->path, dat2->path));
}
