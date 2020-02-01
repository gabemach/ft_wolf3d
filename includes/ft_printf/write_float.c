/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:43:55 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 14:32:57 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		check_floatconv(t_ftpf *ftpf)
{
	long double		num;

	if (ft_strcmp(ftpf->cnvrsn, "L") == 0)
		num = (long double)va_arg(ftpf->ap, long double);
	else if (ft_strcmp(ftpf->cnvrsn, "l") == 0)
		num = (long double)va_arg(ftpf->ap, double);
	else
		num = (long double)va_arg(ftpf->ap, double);
	return (num);
}

t_ftpf			*print_float(t_ftpf *ftpf)
{
	long double		num;
	char			*print;

	if (ftpf->prcisn < 0)
		ftpf->prcisn = 6;
	num = check_floatconv(ftpf);
	print = ftoa(num, ftpf);
	ftpf->printlen = ft_strlen(print);
	check_arg(ftpf, print);
	return (ftpf);
}
