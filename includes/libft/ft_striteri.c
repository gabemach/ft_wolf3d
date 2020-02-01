/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:38:14 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/06 19:57:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int pos;

	pos = 0;
	if (s != NULL && f != NULL)
	{
		while (s[pos] != 0)
		{
			f(pos, &s[pos]);
			pos++;
		}
	}
}
