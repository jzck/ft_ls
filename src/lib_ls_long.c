/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ls_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 17:29:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_long_middle(struct stat *stat, t_pads *pads)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(stat->st_uid)) == NULL)
		return (1);
	if ((grp = getgrgid(stat->st_gid)) == NULL)
		return (1);
	ft_printf(" %*hu", pads->nlink, stat->st_nlink);
	ft_printf(" %-*s", pads->name, pwd->pw_name);
	ft_printf("  %-*s", pads->gr_name, grp->gr_name);
	ft_printf("  %*lld", pads->size, stat->st_size);
	return (0);
}

void	ft_ls_long_date(struct stat *stat)
{
	char	*date;
	char	*day;
	char	*month;
	char	*time;

	date = ctime(&stat->st_mtime);
	month = ft_strsub(date, 4, 3);
	month[0] += 32;
	day = ft_strsub(date, 8, 2);
	time = ft_time_isrecent(stat->st_mtime)
		? ft_strsub(date, 11, 5)
		: ft_strsub(date, 20, 4);
	ft_printf(" %s %s %5s", day, month, time);
}

void	ft_ls_long_type(mode_t m)
{
	char	type;

	type = '\0';
	type = S_ISREG(m) ? '-' : type;
	type = S_ISDIR(m) ? 'd' : type;
	type = S_ISFIFO(m) ? 'p' : type;
	type = S_ISSOCK(m) ? 's' : type;
	type = S_ISCHR(m) ? 'c' : type;
	type = S_ISBLK(m) ? 'b' : type;
	type = S_ISLNK(m) ? 'l' : type;
	ft_printf("%c", type);
}
