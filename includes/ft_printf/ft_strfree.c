/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:43:03 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:25:10 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strfree(char *s1, char *s2, int flag)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	if (flag == 1)
	{
		free(s1);
		return (str);
	}
	else if (flag == 2)
	{
		free(s2);
		return (str);
	}
	else if (flag == 3)
	{
		free(s1);
		free(s2);
		return (str);
	}
	return (str);
}
