/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 15:04:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_dir_get_ents(t_lsdata *topdir)
{
	t_list			*ent;
	struct dirent	*dirent;
	t_lsdata		data;
	DIR				*stream;

	ent = NULL;
	stream = opendir(topdir->path);
	while ((dirent = readdir(stream)))
	{
		data.path = ft_str3join(topdir->path, "/", dirent->d_name);
		lstat(data.path, &data.stat);
		data.dirent = ft_memalloc(sizeof(dirent));
		ft_memcpy(data.dirent, &dirent, sizeof(dirent));
		ft_lstadd(&ent, ft_lstnew(&data, sizeof(data)));
	}
	closedir(stream);
	return (ent);
}
