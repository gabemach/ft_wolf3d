/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:04:26 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/11 17:33:13 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dst;
	char *clean;

	dst = malloc(size);
	clean = dst;
	if (dst)
	{
		while (size != 0)
		{
			*clean++ = 0;
			size--;
		}
		return (dst);
	}
	else
		return (NULL);
}
