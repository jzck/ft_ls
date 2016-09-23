#include "ftls.h"

int		main(int ac, char **av)
{
	t_list	*dirs;
	char	*opts;

	dirs = NULL;
	opts = (char *)malloc(sizeof(char) * 7);
	ft_bzero(opts, 7);
	ft_parse_ls(ac, av, &dirs, opts);
	while (dirs)
		ft_ls(&dirs);
	return (0);
}
