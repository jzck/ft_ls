#include "ftls.h"

void	ft_parse_ls(int ac, char **av, t_list **dirs, char *opts)
{
	int		i;
	DIR		*dir;

	(void)dirs;
	i = ft_parse_ls_options(ac, av, opts);
	ft_printf("options: %s\n", opts);
	ft_strlsort(av + i, ac - i, &ft_strcmp);
	if (i == ac)
		ft_lstadd(dirs, ft_lstnew(opendir("."), sizeof(*dir)));
	while (i < ac)
	{
		dir = opendir(av[i]);
		if (dir)
		{
			ft_lstadd(dirs, ft_lstnew(dir, sizeof(*dir)));
			/* ft_printf("found dir %s\n", av[i]); */
		}
		else
			ft_error_dir(av[i]);
		i++;
	}
}

int		ft_parse_ls_options(int ac, char **av, char *opts)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			j = 1;
			while(av[i][j])
			{
				if (ft_strchr(ALL_OPTS, av[i][j]))
				{
					if (!ft_strchr(opts, av[i][j]))
						ft_strcat(opts, av[i] + j);
				}
				else
					ft_error_option(av[i][j]);
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (i);
}
