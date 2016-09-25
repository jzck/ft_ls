#include "ftls.h"

void	ft_ls_dirs(t_list *dir, char *opts)
{
	t_list		*dir_r;
	t_list		*ent;
	t_lsdata	*dirdata;

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
	}
}

void	ft_ls_files(t_list *ent, t_list *dir, char *opts)
{
	if (ent)
	{
		ft_ent_filter(&ent, opts);
		ft_ent_sort(&ent, opts);
		ft_ent_print(ent, opts, NULL, dir);
	}
}
