#include "ftls.h"

void	ft_parse_ls(int ac, char **av, t_list **dir, t_list **ent, char *opts)
{
	int			i;
	t_lsdata	data;
	DIR			*stream;

	ft_bzero(opts, 7);
	i = ft_parse_ls_options(ac, av, opts);
	/* ft_strlsort(av + i, ac - i, &ft_strcmp); */
	if (ac - i <= 1)
		ft_strcat(opts, "0");
	/* ft_printf("options: %s\n", opts); */
	/* ft_printf("%i, %i\n", i, ac); */
	if (i == ac)
	{
		data.path = ft_strdup(".");
		ft_printf("stat ret: %i\n", stat(data.path, &data.stat));
		ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
	}
	while (i < ac)
	{
		data.path = ft_strdup(av[i]);
		if (stat(data.path, &data.stat) < 0)
		{
			ft_error_dir(data.path);
		}
		else if (!(stream = opendir(data.path)))
		{
			/* ft_printf("found file: %s\n", data.path); */
			ft_lstadd(ent, ft_lstnew(&data, sizeof(data)));
		}
		else
		{
			/* ft_printf("found dir: %s\n", data.path); */
			ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
			closedir(stream);
		}
		i++;
	}
}

int		ft_parse_ls_options(int ac, char **av, char *opts)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			j = 0;
			while(av[i][++j])
			{
				if (ft_strchr(ALL_OPTS, av[i][j]))
				{
					if (!ft_strchr(opts, av[i][j]))
						ft_strcat(opts, av[i] + j);
				}
				else
					ft_error_option(av[i][j]);
			}
		}
		else
			break ;
	}
	return (i);
}
