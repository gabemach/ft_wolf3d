/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:58:30 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/17 16:39:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *out_m;
	char *out_o;

	if (f && s)
	{
		out_o = ft_strnew(ft_strlen(s));
		if (!out_o)
			return (NULL);
		out_m = out_o;
		while (*s != 0)
			*out_m++ = f(*s++);
		return (out_o);
	}
	return (NULL);
}
