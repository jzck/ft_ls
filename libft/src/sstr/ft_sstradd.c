/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:31:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **sstr, char *new)
{
	int		i;
	int		size;
	char	**newlist;

	i = 0;
	size = 0;
	while (sstr && sstr[size])
		size++;
	if (!(newlist = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	while (sstr && *sstr)
		newlist[i++] = *sstr++;
	newlist[i++] = new;
	newlist[i] = NULL;
	return (newlist);
}
