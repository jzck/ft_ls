#include "ftls.h"

void	ft_lsdata_print(t_list *ent)
{
	while (ent)
	{
		ft_printf("found recursively: %s\n", ((t_lsdata*)ent->content)->path);
		ent = ent->next;
	}
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

int		ft_lsdata_cmp0(t_lsdata *dat1, char *dataref)
{
	return (dat1->dirent->d_name[0] != *dataref);
}
