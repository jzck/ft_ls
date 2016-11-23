/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:02:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/23 18:46:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls_parse_files(int ac, char **av, int opts, t_list **dir, t_list **ent)
{
	t_lsdata	data;
	int			i;

	data.dirent = NULL;
	i = -1;
	while (++i < ac)
	{
		if (stat(av[i], &data.stat) < 0)
		{
			if (lstat(av[i], &data.stat) < 0)
			{
				ft_error_dir(av[i]);
				continue ;
			}
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
	int	opts;

	i = 0;
	opts = 0;
	while (str[i])
	{
		if (str[i] == 'l')
		{
			opts |= OPTS_LL;
			opts &= ~OPTS_ONE;
		}
		else if (str[i] == '1')
		{
			opts |= OPTS_ONE;
			opts &= ~OPTS_LL;
		}
		else if (str[i] == 'a')
			opts |= OPTS_LA;
		else if (str[i] == 'c')
		{
			opts &= ~TIME_MASK;
			opts |= OPTS_LC;
		}
		else if (str[i] == 'f')
		{
			opts |= OPTS_LF;
			opts |= OPTS_LA;
		}
		else if (str[i] == 't')
			opts |= OPTS_LT;
		else if (str[i] == 'r')
			opts |= OPTS_LR;
		else if (str[i] == 'd')
		{
			opts &= ~OPTS_UR;
			opts |= OPTS_LD;
		}
		else if (str[i] == 'p')
			opts |= OPTS_LP;
		else if (str[i] == 'u')
		{
			opts &= ~TIME_MASK;
			opts |= OPTS_LU;
		}
		else if (str[i] == 'A')
			opts |= OPTS_UA;
		else if (str[i] == 'R')
		{
			if (!(opts & OPTS_LD))
				opts |= OPTS_UR;
		}
		else if (str[i] == 'U')
		{
			opts &= ~TIME_MASK;
			opts |= OPTS_UU;
		}
		else if (str[i] == 'S')
			opts |= OPTS_US;
		else
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
