#ifndef FTLS_H
# define FTLS_H
# define ALL_OPTS "lRart"
# include "libft.h"
# include <dirent.h>

int		ft_parse_ls_options(int ac, char **av, char *opts);
void	ft_parse_ls(int ac, char **av, t_list **dirs, char * opts);

void	ft_ls(t_list **dirs);

void	ft_error_option(char c);
void	ft_error_dir(char *s);

#endif
