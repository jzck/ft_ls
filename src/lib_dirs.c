/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 15:30:07 by jhalford         ###   ########.fr       */
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
		data.path = ft_strjoin(topdir->path, "/");
		data.path = ft_strjoin(data.path, dirent->d_name);
		lstat(data.path, &data.stat);
		data.dirent = dirent;
		ft_lstadd(&ent, ft_lstnew(&data, sizeof(data)));
	}
	closedir(stream);
	return (ent);
}
