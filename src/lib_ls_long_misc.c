#include "ftls.h"

void	ft_ls_long_lnk(t_lsdata *data)
{
	struct stat		stat;
	struct dirent	*dirent;

	dirent = data->dirent;
	stat = data->stat;

	if (dirent->d_type == DT_LNK)
		ft_printf(" -> unknown\n");
	else
		ft_printf("\n");
}

int		ft_ls_long_xattr(char *path)
{
	int		n;
	char	x;

	if ((n = ft_xattr_count(path)) == -1)
		return (1);
	x = n > 0 ? '@' : '\0';
	ft_printf("%1c", x);
	return (0);
}

int		ft_ls_long_total(t_list *ent)
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
	ft_printf("total %i\n", total);
	return (0);
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
