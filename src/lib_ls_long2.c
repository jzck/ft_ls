#include "ftls.h"
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
	struct stat		statbuf;
	int				ret;

	ft_bzero(&statbuf, sizeof(statbuf));
	if (S_ISLNK(data->stat.st_mode))
	{
		printf(" -> %lld\n", statbuf.st_size);
		printf("path: %s\n", data->path);
		if ((ret = stat(data->path, &statbuf)) == -1)
			printf("stat=%i, errno=%i\n", ret, errno);
	}
	else
		printf("\n");
	return (0);
}

int		ft_ls_long_xattr(char *path)
{
	int		n;
	char	x;

	x = ' ';
	if ((n = ft_xattr_count(path)) == -1)
	{
		printf("\ncouldnt get xattr: %i\n", n);
		return (1);
	}
	if (n > 0)
		x = '@';
	/* ft_printf("%c", x); */
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
		/* dirent = data->dirent; */
		ent = ent->next;

		total += stat.st_blocks;
	}
	printf("total %i\n", total);
}

int		ft_ls_long_pads(t_list *ent, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		stat;
	t_lsdata		*data;

	while (ent)
	{
		data = ent->content;
		stat = data->stat;
		/* dirent = data->dirent; */
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
