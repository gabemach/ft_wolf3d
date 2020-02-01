/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:26:57 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/27 21:44:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *i;
	unsigned char *j;

	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*i == *j && n-- > 0)
	{
		i++;
		j++;
		if (n == 0)
		{
			return (0);
		}
	}
	if (*i != *j)
	{
		return (*i - *j);
	}
	return (0);
}
