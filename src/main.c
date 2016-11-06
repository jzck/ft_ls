#include "ftls.h"

int		main(int ac, char **av)
{
	t_list		*dir;
	t_list		*ent;
	char	*opts;

	dir = NULL;
	ent = NULL;
	opts = ft_parse_ls(ac, av, &dir, &ent);
	ft_ls_files(ent, dir, opts);
	ft_ls_dirs(dir, opts);
	return (errno);
}
