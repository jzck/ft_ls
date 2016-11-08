/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:10:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 16:20:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS_LEGAL_OPTS			"larRt"
# define LS_MSG_ILLEGAL_OPT		"ft_ls: illegal option -- %c\n"
# define LS_MSG_USAGE			"usage: ls [-%s] [file ...]\n"
# define LS_MSG_FILE_ERR		"ls: %s: no such file or directory\n"
# define FT_MINORBITS			20
# define FT_MINORMASK			((1U << FT_MINORBITS) - 1)
# define FT_MINOR(dev)			((unsigned int) ((dev) >> FT_MINORBITS))
# define FT_MAJOR(dev)			((unsigned int) ((dev) & FT_MINORMASK))
# define FT_MKDEV(ma,mi)		(((ma) << FT_MINORBITS) | (mi))

# include "libft.h"
# include <errno.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>

struct	s_lsdata
{
	struct stat		stat;
	char			*path;
	struct dirent	*dirent;
};

struct	s_pads
{
	int		nlink;
	int		name;
	int		gr_name;
	int		size;
	int		major;
	int		minor;
};

typedef struct s_lsdata		t_lsdata;
typedef struct s_pads		t_pads;

char	*ft_ls_parse(int ac, char **av, t_list **dir, t_list **ent);

void	ft_ls_dirs(t_list *dir, char *opts);
void	ft_ls_files(t_list *ent, t_list *dir, char *opts);

void	ft_lsdata_filename(t_lsdata *data);
int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp_time(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp0(t_lsdata *dat1, char *dataref);

void	ft_ent_filter(t_list **ent, char *opts);
void	ft_ent_sort(t_list **ent, char *opts);
void	ft_ent_print(
		t_list *ent, char *opts, t_lsdata *topdir, t_list *nextdir);

t_list	*ft_ent_get_dirs(t_list *ent);
t_list	*ft_dir_get_ents(t_lsdata *topdir);

void	ft_ls_short(t_list *ent);

int		ft_ls_long(t_list *ent, t_lsdata *topdir);
int		ft_ls_long_print(t_list *ent, t_pads pads);

void	ft_ls_long_total(t_list *ent);
int		ft_ls_long_pads(t_list *ent, t_pads *pads);
void	ft_ls_long_type(mode_t m);
void	ft_ls_long_rights(mode_t m);
int		ft_ls_long_xattr(mode_t m, char *path);
int		ft_ls_long_middle(struct stat *stat, t_pads *pads);
void	ft_ls_long_date(struct stat *stat);
int		ft_ls_long_lnk(t_lsdata *data);

void	ft_error_option(char c);
void	ft_error_dir(char *s);

void	ft_ent_free(void *ptr, size_t size);
#endif