/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:40:18 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/27 21:32:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*s1;
	char			*s2;
	size_t			i;

	s1 = (char *)src;
	s2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		if ((unsigned char)s1[i] == (unsigned char)c)
			return ((void *)(&(s2[i + 1])));
		i++;
	}
	return (NULL);
}
