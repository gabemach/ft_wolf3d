/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:43:22 by gmachado          #+#    #+#             */
/*   Updated: 2019/05/29 12:57:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_convert(char c, int base)
{
	int	res;

	if (c >= '0' && c <= '9')
		res = c - 48;
	else if (c >= 'a' && c <= 'z')
		res = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		res = c - 65 + 10;
	else
		res = -1;
	if (res < base && res != -1)
		return (res);
	else
		return (-1);
}

static int	num_len(char *str, int base)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (num_convert(str[len], base) == -1)
			break ;
		len++;
	}
	return (len);
}

int			ft_atoi_base(char *num, int base)
{
	int	res;
	int	len;

	if (base == 10)
		return (ft_atoi(num));
	while (*num == ' ' || *num == '\t' || *num == '\n'
			|| *num == '\v' || *num == '\r' || *num == '\f')
		num++;
	res = 0;
	len = num_len(num, base) - 1;
	while (*num && len >= 0 && num_convert(*num, base) != -1)
	{
		res += num_convert(*num, base) * ft_power(base, len);
		num++;
		len--;
	}
	return (res);
}
