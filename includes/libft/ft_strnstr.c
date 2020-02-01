/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:27:24 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/26 17:40:14 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*s2 == 0)
		return ((char*)s1);
	while (s1[i] != 0 && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != 0 && j + i < len)
			j++;
		if (j == ft_strlen(s2))
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
