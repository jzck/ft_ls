#include "ftls.h"

void	ft_ent_handle(t_list **ent, t_lsdata *topdir, char *opts, int (*ft_sort)())
{
	ft_lst_sort(ent, ft_sort);
	if (ft_strchr(opts, 'r'))
		ft_lst_reverse(ent);
	if (!ft_strchr(opts, 'a'))
		ft_lst_delif(ent, ".", &ft_lsdata_cmp0, &ft_lst_cfree);
	ft_ls_print(*ent, opts, topdir);
}

t_list	*ft_ent_get_dirs(t_list *ent)
{
	t_lsdata		*data;
	struct dirent	*dirent;
	t_list			*dir;
	t_list			*tmp;

	/* ft_printf("checking dir: %s\n", topdir->path); */
	dir = NULL;
	while (ent)
	{
		data = ent->content;
		dirent = data->dirent;
		tmp = ent;
		ent = ent->next;
		/* ft_printf("checking: %s\n", data->path); */
		if (dirent->d_type == DT_DIR
				&& ft_strcmp(dirent->d_name, ".")
				&& ft_strcmp(dirent->d_name, ".."))
		{
			/* data->path = ft_strjoin(topdir->path, "/"); */
			/* data->path = ft_strjoin(data->path, dirent->d_name); */
			/* stat(data->path, &data->stat); */
			/* ft_printf("found dir: %s\n", data->path); */
			ft_lsteadd(&dir, tmp);
		}
		/* else */
			/* ft_printf("%s is not a dir\n", data->path); */
	}
	return (dir);
}
