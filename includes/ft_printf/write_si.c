/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_si.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:30:49 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:25:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		print_sign(t_ftpf *ftpf)
{
	if (ftpf->sinum < 0 || ftpf->argflag[1] == '+')
	{
		ftpf->width -= 1;
		ftpf->fmtlen += 1;
	}
	if (ftpf->sinum < 0)
		ft_putchar('-');
	else if (ftpf->sinum >= 0 && ftpf->argflag[1] == '+')
		ft_putchar('+');
}

void		si_arg(t_ftpf *ftpf, char *print)
{
	if (ftpf->argflag[2] == ' ' && ftpf->argflag[1] != '+' && ftpf->sinum >= 0)
	{
		ftpf->width -= 1;
		print_arg(ftpf, ' ', 1, 1);
	}
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] == '0')
	{
		print_sign(ftpf);
		print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
	}
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] != '0')
	{
		if (ftpf->sinum < 0 || ftpf->argflag[1] == '+')
			ftpf->width -= 1;
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
		print_sign(ftpf);
	}
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
}

char		*check_sign(char *print, t_ftpf *ftpf)
{
	if (ftpf->sinum < 0 && ftpf->argflag[0] == '-')
	{
		print = strfree("-", print, 2);
		ftpf->printlen += 1;
		ftpf->fmtlen += 1;
	}
	else if (ftpf->sinum >= 0 && ftpf->argflag[1] == '+' &&
			ftpf->argflag[0] == '-')
	{
		if (print == NULL)
		{
			print = ft_strnew(1);
			print = "+";
		}
		else
			print = strfree("+", print, 2);
		ftpf->printlen += 1;
		ftpf->fmtlen += 1;
	}
	return (print);
}

intptr_t	check_siconv(t_ftpf *ftpf)
{
	intptr_t	num;

	if (ft_strcmp(ftpf->cnvrsn, "hh") == 1)
		num = (signed char)va_arg(ftpf->ap, int);
	else if (ft_strcmp(ftpf->cnvrsn, "h") == 0)
		num = (short)va_arg(ftpf->ap, int);
	else if (ft_strcmp(ftpf->cnvrsn, "l") == 0)
		num = (long)va_arg(ftpf->ap, void *);
	else if (ft_strcmp(ftpf->cnvrsn, "ll") == 1)
		num = (long long)va_arg(ftpf->ap, void *);
	else
		num = va_arg(ftpf->ap, int);
	ftpf->sinum = num;
	return (num);
}

t_ftpf		*print_si(t_ftpf *ftpf)
{
	char		*print;

	if (ftpf->prcisn < 0)
		ftpf->prcisn = 1;
	else
		ftpf->argflag[3] = '\0';
	ftpf->sinum = check_siconv(ftpf);
	print = simaxtoa_base(10, ftpf->sinum);
	ftpf->printlen = ft_strlen(print);
	if (ftpf->sinum == 0 && ftpf->prcisn == 0 &&
			ft_strcmp(ftpf->cnvrsn, "\0") == 0)
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	print = check_prcisn(ftpf, print);
	print = check_sign(print, ftpf);
	si_arg(ftpf, print);
	return (ftpf);
}
