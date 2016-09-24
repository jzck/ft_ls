#include "ftls.h"

void	ft_ls_print(t_list *ent, char *opts, t_lsdata *topdir)
{
	char	*opt;

	if (!(opt = ft_strchr(opts, '0')))
		ft_ls_print_header(topdir->path);
	else
		*opt = '.';
	ft_ls_print_dirents(ent, opts);
	ft_printf("\n");
}

void	ft_ls_l(t_lsdata *data)
{
	char	*date;

	/* date = ctime(&data->stat.st_mtimespec.tv_sec); */
	date = ctime(&data->stat.st_mtime);
	date[ft_strlen(date) - 1] = '\0';
	ft_printf("%s %s\n", date, data->dirent->d_name);
}

void	ft_ls_print_dirents(t_list *ent, char *opts)
{
	t_lsdata		*data;
	struct dirent	*dirent;

	while (ent)
	{
		data = ent->content;
		dirent = data->dirent;
		if (ft_strchr(opts, 'l'))
			ft_ls_l(data);
		else
			ft_printf("%s\n", dirent->d_name);
		ent = ent->next;
	}
}

void	ft_ls_print_header(char *dirname)
{
	ft_printf("%s:\n", dirname);
}
