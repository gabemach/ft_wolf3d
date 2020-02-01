/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:03:54 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/27 16:26:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*res;

	if (s1 && s2)
	{
		if ((dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			res = dst;
			while (*s1)
				*(dst++) = *(s1++);
			while (*s2)
				*(dst++) = *(s2++);
			*dst = '\0';
			return (res);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
