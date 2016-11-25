/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:02:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 18:31:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opts	g_opts[] =
{
	{'A', OPTS_UA, 0},
	{'F', OPTS_UF, OPTS_LP},
	{'G', OPTS_UG, 0},
	{'R', OPTS_UR, 0},
	{'S', OPTS_US, 0},
	{'T', OPTS_UT, 0},
	{'U', OPTS_UU, TIME_MASK},
	{'a', OPTS_LA, 0},
	{'c', OPTS_LC, 0},
	{'d', OPTS_LD, 0},
	{'f', OPTS_LF, 0},
	{'g', OPTS_LG, 0},
	{'l', OPTS_LL, 0},
	{'o', OPTS_LO, 0},
	{'p', OPTS_LP, OPTS_UF},
	{'r', OPTS_LR, 0},
	{'t', OPTS_LT, 0},
	{'u', OPTS_LU, TIME_MASK},
	{'1', OPTS_ONE, (OPTS_LL | OPTS_LG | OPTS_LO)},
	{0, 0, 0},
};


static void	ft_ls_parse_files(int ac, char **av, int opts, t_list **dir, t_list **ent)
{
	t_lsdata	data;
	int			i;

	data.dirent = NULL;
	i = -1;
	while (++i < ac)
	{
		if (stat(av[i], &data.stat) < 0)
			if (lstat(av[i], &data.stat) < 0)
			{
				ft_error_dir(av[i]);
				continue ;
			}
		if (opts & OPTS_LL || !S_ISDIR(data.stat.st_mode))
			if (lstat(av[i], &data.stat) < 0)
			{
				ft_error_dir(av[i]);
				continue ;
			}
		data.path = ft_strdup(av[i]);
		if (opts & OPTS_LD || !S_ISDIR(data.stat.st_mode))
			ft_lstadd(ent, ft_lstnew(&data, sizeof(data)));
		else
			ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
	}
}

static int	ft_getopts(char *str)
{
	int	i;
	int	j;
	int	opts;

	i = 0;
	opts = 0;
	while (str[i])
	{
		j = -1;
		while (g_opts[++j].id)
			if (g_opts[j].id == str[i])
			{
				opts &= ~g_opts[j].off;
				opts |= g_opts[j].on;
				break ;
			}
		if (!ft_strchr(LS_LEGAL_OPTS, str[i]))
		{
			ft_error_option(str[i]);
			exit(1);
		}
		i++;
	}
	return (opts);
}

static int	ft_ls_parse_options(int ac, char **av, int *opts)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (!av[i][1])
				break ;
			if (av[i][1] == '-' && !av[i][2])
			{
				i++;
				break ;
			}
			*opts |= ft_getopts(av[i] + 1);
		}
		else
			break ;
	}
	return (i);
}

int			ft_ls_parse(int ac, char **av, t_list **dir, t_list **ent)
{
	int		i;
	int		opts;

	opts = 0;
	i = ft_ls_parse_options(ac, av, &opts);
	opts |= (ac - i > 1) ? OPTS_HEAD : 0;
	ft_sstrsort(av + i, &ft_strcmp);
	if (i == ac)
		ft_ls_parse_files(1, (char*[2]){"."},  opts,dir, ent);
	else
		ft_ls_parse_files(ac - i, av + i, opts, dir, ent);
	return (opts);
}
