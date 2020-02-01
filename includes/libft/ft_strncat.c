/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:32:49 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/17 17:36:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *original;

	original = s1;
	s1 = &s1[ft_strlen(s1)];
	while (*s2 != 0 && n > 0)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = 0;
	return (original);
}
