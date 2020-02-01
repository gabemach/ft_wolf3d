/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:06:41 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/16 17:44:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*check_si_sign(int len, intptr_t num)
{
	char	*str;

	if (!(str = ft_strnew(len)))
	{
		free(str);
		return (NULL);
	}
	if (num == 0)
		str[0] = '0';
	return (str);
}

int			simax_len(int base, intptr_t num)
{
	int		len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

char		*simaxtoa_base(int base, intptr_t num)
{
	int		len;
	char	*str;

	len = simax_len(base, num);
	str = check_si_sign(len, num);
	while (num != 0 && len >= 0)
	{
		if (num < 0)
			str[len-- - 1] = -(num % base) + 48;
		else
			str[len-- - 1] = num % base + 48;
		num /= base;
	}
	return (str);
}

static int	uimax_len(int base, uintptr_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

char		*uimaxtoa_base(int base, uintptr_t num, t_ftpf *ftpf)
{
	int		len;
	char	*str;

	len = uimax_len(base, num);
	str = ft_strnew(len);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	if (num == 0)
		str[0] = '0';
	while (num != 0 && len >= 0)
	{
		if ((num % base) >= 10)
			str[len-- - 1] = ftpf->specflag == 'X' ? num % base + 55 :
					num % base + 87;
		else
			str[len-- - 1] = num % base + 48;
		num /= base;
	}
	return (str);
}
