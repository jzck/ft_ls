/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 13:11:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*elem;

	out = NULL;
	while (lst)
	{
		elem = (*f)(lst);
		elem = ft_lstnew(elem->content, elem->content_size);
		ft_lsteadd(&out, elem);
		lst = lst->next;
	}
	return (out);
}
