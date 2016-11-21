/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:56:53 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 12:18:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	size;
	size_t	j;

	size = ft_strlen(s1);
	j = 0;
	while (s2 && s2[j])
	{
		s1[size + j] = s2[j];
		j++;
	}
	s1[size + j] = '\0';
	return (s1);
}
