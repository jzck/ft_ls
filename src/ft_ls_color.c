/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:39:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 16:00:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_color(mode_t m)
{
	char	fg[20];
	char	bg[20];

	ft_strcpy(fg, FG_DEFAULT);
	ft_strcpy(bg, BG_DEFAULT);
	ft_strcpy(fg, S_ISDIR(m) ? FG_BLUE : fg);
	ft_strcpy(fg, S_ISLNK(m) ? FG_MAGENTA : fg);
	ft_strcpy(fg, S_ISSOCK(m) ? FG_GREEN : fg);
	ft_strcpy(fg, S_ISFIFO(m) ? FG_YELLOW : fg);
	ft_strcpy(fg, S_ISREG(m) && (S_IXUGO & m) ? FG_RED : fg);
	ft_strcpy(fg, S_ISBLK(m) ? FG_BLUE : fg);
	ft_strcpy(bg, S_ISBLK(m) ? BG_CYAN : bg);
	ft_strcpy(fg, S_ISCHR(m) ? FG_BLUE : fg);
	ft_strcpy(bg, S_ISCHR(m) ? BG_YELLOW : bg);
	ft_strcpy(fg, S_ISREG(m) && (S_IXUGO & m) &&
			(S_ISGID & m) ? FG_BLACK : fg);
	ft_strcpy(bg, S_ISREG(m) && (S_IXUGO & m) &&
			(S_ISGID & m) ?  BG_CYAN : bg);
	ft_strcpy(fg, S_ISREG(m) && (S_IXUGO & m) &&
			(S_ISUID & m) ?  FG_BLACK : fg);
	ft_strcpy(bg, S_ISREG(m) && (S_IXUGO & m) &&
			(S_ISUID & m) ?  BG_RED : bg);
	ft_strcpy(fg, S_ISDIR(m) && (S_IWOTH & m) && (S_ISVTX & m) ? FG_BLACK : fg);
	ft_strcpy(bg, S_ISDIR(m) && (S_IWOTH & m) && (S_ISVTX & m) ? BG_GREEN : bg);
	ft_strcpy(fg, S_ISDIR(m) && (S_IWOTH & m) && !(S_ISVTX & m) ? FG_BLACK : fg);
	ft_strcpy(bg, S_ISDIR(m) && (S_IWOTH & m) && !(S_ISVTX & m) ? BG_YELLOW : bg);
	ft_color_set(fg, bg);
}
