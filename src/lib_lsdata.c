/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_lsdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 13:40:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lsdata_filename(t_lsdata *data)
{
	struct dirent	*dirent;

	dirent = data->dirent;
	if (data->path)
		ft_printf("%s", ft_path_notdir(data->path));
	else if (dirent && *dirent->d_name)
		ft_printf("%s", dirent->d_name);
	else
		ft_printf("noname!");
}

int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2)
{
	return (ft_strcmp(dat1->path, dat2->path));
}

int		ft_lsdata_cmp_time(t_lsdata *dat1, t_lsdata *dat2)
{
	if (dat2->stat.st_mtime - dat1->stat.st_mtime)
		return (dat2->stat.st_mtime - dat1->stat.st_mtime);
	else
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
