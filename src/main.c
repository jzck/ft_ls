#include "ftls.h"

int		main(int ac, char **av)
{
	t_list		*dir;
	t_list		*dir_r;
	t_list		*ent;
	t_lsdata	*dirdata;
	int			(*ft_sort)();

	char	*opts;
	dir = NULL;
	ent = NULL;
	opts = (char *)malloc(sizeof(char) * 7);
	ft_parse_ls(ac, av, &dir, &ent, opts);
	ft_sort = &ft_lsdata_cmp_name;
	if (ft_strchr(opts, 't'))
		ft_sort = &ft_lsdata_cmp_time;
	ft_lst_sort(&dir, ft_sort);
	ft_lst_sort(&ent, ft_sort);
	if (ft_strchr(opts, 'r'))
	{
		ft_lst_reverse(&dir);
		ft_lst_reverse(&ent);
	}
	if (ent)
		ft_ent_handle(&ent, dir->content, opts, ft_sort);
	while (dir)
	{
		dirdata = dir->content;
		dir = dir->next;
		/* ft_lstfree(ent); */
		ent = ft_dir_get_ents(dirdata);
		ft_ent_handle(&ent, dirdata, opts, ft_sort);
		if (ft_strchr(opts, 'R'))
		{
			dir_r = ft_ent_get_dirs(ent);
			ft_lst_merge(&dir_r, dir);
			dir = dir_r;
		}
		/* ft_lsdata_print(dir); */
	}
	return (0);
}
