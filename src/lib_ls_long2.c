/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls_long2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:01:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 17:38:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

void	ft_ls_long_rights(int st_mode)
{
	int		i;
	char	*rights;

	i = 0;
	rights = ft_itoa_base(st_mode, "01", "");
	rights = rights + ft_strlen(rights) - 9;
	while (rights[i])
	{
		if (rights[i] == '0')
			rights[i] = '-';
		else
		{
			if (i % 3 == 0)
				rights[i] = 'r';
			else if (i % 3 == 1)
				rights[i] = 'w';
			else if (i % 3 == 2)
				rights[i] = 'x';
		}
		i++;
	}
	ft_printf("%s", rights);
}

int		ft_ls_long_lnk(t_lsdata *data)
{
	int				ret;
	char			buf[1024];

	if (S_ISLNK(data->stat.st_mode))
	{
		if ((ret = readlink(data->path, buf, 1024)) < 0)
			return (-1);
		buf[ret] = '\0';
		ft_printf(" -> %s\n", buf);
	}
	else
		ft_putendl("");
	return (0);
}

int		ft_ls_long_xattr(char *path)
{
	int		n;
	char	x;

	x = ' ';
	if ((n = ft_xattr_count(path)) == -1)
	{
		ft_printf("\ncouldnt get xattr: %i\n", n);
		return (1);
	}
	if (n > 0)
		x = '@';
	ft_putchar(x);
	return (0);
}

void	ft_ls_long_total(t_list *ent)
{
	struct stat		stat;
	t_lsdata		*data;
	int				total;

	total = 0;
	while (ent)
	{
		data = ent->content;
		stat = data->stat;
		ent = ent->next;
		total += stat.st_blocks;
	}
	ft_printf("total %i\n", total);
}

int		ft_ls_long_pads(t_list *ent, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		stat;
	t_lsdata		*data;

	pads->nlink = 0;
	pads->name = 0;
	pads->gr_name = 0;
	pads->size = 0;
	while (ent)
	{
		data = ent->content;
		stat = data->stat;
		ent = ent->next;
		if ((pwd = getpwuid(stat.st_uid)) == NULL)
			return (1);
		if ((grp = getgrgid(stat.st_gid)) == NULL)
			return (1);
		pads->nlink = FT_MAX(pads->nlink, (int)ft_uilen(stat.st_nlink));
		pads->name = FT_MAX(pads->name, (int)ft_strlen(pwd->pw_name));
		pads->gr_name = FT_MAX(pads->gr_name, (int)ft_strlen(grp->gr_name));
		pads->size = FT_MAX(pads->size, (int)ft_ilen(stat.st_size));
	}
	return (0);
}
