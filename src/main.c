#include "ftls.h"

int		main(int ac, char **av)
{
	t_list		*dir;
	t_list		*dir_r;
	t_list		*ent;
	t_lsdata	*dirdata;

	char	*opts;
	dir = NULL;
	ent = NULL;
	opts = (char *)malloc(sizeof(char) * 7);
	ft_parse_ls(ac, av, &dir, &ent, opts);
	if (ent)
	{
		ft_ent_filter(&ent, opts);
		ft_ent_sort(&ent, opts);
		ft_ent_print(ent, opts, NULL, dir);
	}
	ft_ent_sort(&dir, opts);
	while (dir)
	{
		dirdata = dir->content;
		dir = dir->next;
		/* ft_lstfree(ent); */
		ent = ft_dir_get_ents(dirdata);
		ft_ent_filter(&ent, opts);
		ft_ent_sort(&ent, opts);
		ft_ent_print(ent, opts, dirdata, dir);
		if (ft_strchr(opts, 'R'))
		{
			dir_r = ft_ent_get_dirs(ent);
			ft_lst_merge(&dir_r, dir);
			dir = dir_r;
		}
		/* if (dir) */
		/* 	ft_printf("\n"); */
		/* ft_lsdata_print(dir); */
	}
	return (errno);
}
