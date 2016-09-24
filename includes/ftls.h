#ifndef FTLS_H
# define FTLS_H
# define ALL_OPTS "lRart"
# include "libft.h"
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>

typedef struct	s_lsdata
{
	struct stat		stat;
	char			*path;
	struct dirent	*dirent;
}				t_lsdata;

int		ft_parse_ls_options(int ac, char **av, char *opts);
void	ft_parse_ls(int ac, char **av, t_list **dir, t_list **ent, char *opts);

void	ft_lsdata_print(t_list *ent);
int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp_time(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp0(t_lsdata *dat1, char *dataref);

void	ft_ent_handle(t_list **ent, t_lsdata *topdir, char *opts, int (*ft_sort)());
t_list	*ft_ent_get_dirs(t_list *ent);

t_list	*ft_dir_get_ents(t_lsdata *dir);

void	ft_ls_print(t_list *ent, char *opts, t_lsdata *topdir);
void	ft_ls_print_header(char *dirname);
void	ft_ls_print_dirents(t_list *ent, char *opts);

void	ft_error_option(char c);
void	ft_error_dir(char *s);

#endif
