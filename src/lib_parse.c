/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:02:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 16:26:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls_parse_files(int ac, char **av, t_list **dir, t_list **ent)
{
	DIR			*stream;
	t_lsdata	data;
	int			i;

	data.dirent = NULL;
	i = 0;
	while (i < ac)
	{
		data.path = ft_strdup(av[i]);
		if (lstat(data.path, &data.stat) < 0)
			ft_error_dir(data.path);
		else if (!(stream = opendir(data.path)))
			ft_lstadd(ent, ft_lstnew(&data, sizeof(data)));
		else
		{
			ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
			closedir(stream);
		}
		i++;
	}
}

static int	ft_ls_parse_options(int ac, char **av, char *opts)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			j = 0;
			while (av[i][++j])
			{
				if (!ft_strchr(LS_LEGAL_OPTS, av[i][j]))
				{
					ft_error_option(av[i][j]);
					exit(1);
				}
				else if (!ft_strchr(opts, av[i][j]))
					ft_strcat(opts, av[i] + j);
			}
		}
		else
			break ;
	}
	return (i);
}

char		*ft_ls_parse(int ac, char **av, t_list **dir, t_list **ent)
{
	int			i;
	char		*opts;
	t_lsdata	data;

	if (!(opts = (char *)ft_strnew(sizeof(char) * 7)))
		return (NULL);
	i = ft_ls_parse_options(ac, av, opts);
	ft_strcat(opts, (ac - i <= 1) ? "0" : "");
	if (i == ac)
	{
		data.path = ft_strdup(".");
		data.dirent = NULL;
		ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
	}
	ft_ls_parse_files(ac - i, av + i, dir, ent);
	return (opts);
}
