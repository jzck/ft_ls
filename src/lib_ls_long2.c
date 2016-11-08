/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls_long2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:01:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 16:26:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_long_rights(mode_t m)
{
	int		i;
	char	*rights;

	i = 0;
	rights = ft_itoa_base(m, "01", "");
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

int		ft_ls_long_xattr(mode_t m, char *path)
{
	int		n;
	char	x;

	x = ' ';
	n = 0;
	if (!(m & (S_IFCHR | S_IFBLK)))
		if ((n = ft_xattr_count(path)) == -1)
		{
			;
			/* ft_printf("\ncouldnt get xattr: %i\n", n); */
			/* return (1); */
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

#define FT_MAX_WR(a,b)	a = FT_MAX(a,b)

int		ft_ls_long_pads(t_list *ent, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		stat;

	ft_bzero(pads, sizeof(*pads));
	while (ent)
	{
		stat = ((t_lsdata*)ent->content)->stat;
		ent = ent->next;
		if (!(pwd = getpwuid(stat.st_uid)))
			return (1);
		if (!(grp = getgrgid(stat.st_gid)))
			return (1);
		FT_MAX_WR(pads->name, (int)ft_strlen(pwd->pw_name));
		FT_MAX_WR(pads->gr_name, (int)ft_strlen(grp->gr_name));
		FT_MAX_WR(pads->nlink, (int)ft_uilen(stat.st_nlink));
		FT_MAX_WR(pads->size, (int)ft_ilen(stat.st_size));
		if (S_ISCHR(stat.st_mode) || S_ISBLK(stat.st_mode))
		{
			FT_MAX_WR(pads->minor, (int)ft_ilen(minor(stat.st_rdev)));
			FT_MAX_WR(pads->major, (int)ft_ilen(major(stat.st_rdev)));
		}
	}
	pads->size = FT_MAX(pads->size, pads->minor + pads->major + 3);
	return (0);
}
