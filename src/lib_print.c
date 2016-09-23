#include "ftls.h"

void	ft_ls(t_list **dirs_p)
{
	t_list			*ents;
	struct dirent	*dirent;
	DIR				*dir;

	ents = NULL;
	dir = (*dirs_p)->content;;
	while ((dirent = readdir(dir)))
	{
		ft_lstadd(&ents, ft_lstnew(dirent, sizeof(*dirent)));
	}
	*dirs_p = (*dirs_p)->next;
}
