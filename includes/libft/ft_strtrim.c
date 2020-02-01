/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:24:25 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/27 21:07:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimlen(char const *s)
{
	int	i;

	i = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (*s)
	{
		s++;
		i++;
	}
	if ((*(s - 1) == ' ' || *(s - 1) == '\t' || *(s - 1) == '\n') && i > 1)
	{
		s--;
		while (*s == ' ' || *s == '\t' || *s == '\n')
		{
			i--;
			s--;
		}
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	char	*out;

	if (s == NULL)
		return (NULL);
	beg = 0;
	end = trimlen(s);
	out = ft_strnew(end - 1);
	if (out == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (end-- > 1)
		out[beg++] = *(s++);
	out[beg] = '\0';
	return (out);
}
