#include "ftls.h"

int		ft_ls_long(t_list *ent)
{
	t_lsdata		*data;
	struct stat		stat;
	struct dirent	*dirent;
	t_pads			pads = {0, 0, 0, 0};

	ft_ls_long_total(ent);
	if (ft_ls_long_pads(ent, &pads))
		return (1);
	while (ent)
	{
		data = ent->content;
		stat = data->stat;
		dirent = data->dirent;
		ent = ent->next;

		ft_ls_long_type(dirent->d_type);
		ft_ls_long_rights(stat.st_mode);
		if (ft_ls_long_xattr(dirent->d_name))
			return (1);
		if (ft_ls_long_middle(&stat, &pads))
			return (1);
		ft_ls_long_date(&stat);
		ft_printf(" %s", data->dirent->d_name);
		ft_ls_long_lnk(data);
	}
	return (0);
}

int		ft_ls_long_middle(struct stat *stat, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(stat->st_uid)) == NULL)
		return (1);
	if ((grp = getgrgid(stat->st_gid)) == NULL)
		return (1);
	printf(" %*hu", pads->nlink, stat->st_nlink);
	printf(" %-*s", pads->name, pwd->pw_name);
	printf("  %-*s", pads->gr_name, grp->gr_name);
	printf("  %*lld", pads->size, stat->st_size);
	fflush(stdout);
	return (0);
}

void	ft_ls_long_date(struct stat *stat)
{
	char	*date;
	char	*day;
	char	*month;
	char	*time;

	date = ctime(&stat->st_mtime);
	month = ft_strsub(date, 4, 3);
	month[0] += 32;
	day = ft_strsub(date, 8, 2);
	time = ft_time_isrecent(stat->st_mtime)
		? ft_strsub(date, 11, 5)
		: ft_strsub(date, 20, 4);
	ft_printf(" %s %s %5s", day, month, time);
}

void	ft_ls_long_type(unsigned char d_type)
{
	char	type;

	type = '\0';
	type = d_type == DT_REG ? '-' : type;
	type = d_type == DT_DIR ? 'd' : type;
	type = d_type == DT_FIFO ? 'p' : type;
	type = d_type == DT_SOCK ? 's' : type;
	type = d_type == DT_CHR ? 'c' : type;
	type = d_type == DT_BLK ? 'b' : type;
	type = d_type == DT_LNK ? 'l' : type;
	ft_printf("%c", type);
}

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
