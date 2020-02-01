/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:37:45 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/13 16:45:36 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *final;

	final = dst;
	while (*src != 0 && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dst++ = 0;
		len--;
	}
	return (final);
}
