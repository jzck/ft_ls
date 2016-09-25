#include "ftls.h"

void	ft_ls_short(t_list *ent)
{
	while (ent)
	{
		ft_lsdata_filename(ent->content);
		ft_printf("\n");
		ent = ent->next;
	}
}
