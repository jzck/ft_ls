#include "ftls.h"

void	ft_ls_print(t_list *ent, char *opts, t_lsdata *topdir)
{
	char	*opt;

	if (!(opt = ft_strchr(opts, '0')))
		ft_ls_print_header(topdir->path);
	else
		*opt = '.';
	if (ent)
	{
		if (ft_strchr(opts, 'l'))
			ft_ls_long(ent);
		else
			ft_ls_short(ent);
	}
}

void	ft_ls_short(t_list *ent)
{
	t_lsdata		*data;
	struct dirent	*dirent;

	while (ent)
	{
		data = ent->content;
		dirent = data->dirent;
		ent = ent->next;
		ft_printf("%s\n", dirent->d_name);
	}
}

void	ft_ls_print_header(char *dirname)
{
	ft_printf("%s:\n", dirname);
}
