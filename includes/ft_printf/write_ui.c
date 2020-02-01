/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:39:01 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:30:42 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ui_arg(t_ftpf *ftpf, char *print)
{
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] == '0')
	{
		if (ftpf->argflag[4] == '#' && (ftpf->specflag == 'x' ||
					ftpf->specflag == 'X'))
		{
			ftpf->specflag == 'x' ? ft_putstr("0x") : ft_putstr("0X");
			ftpf->width -= 2;
			ftpf->fmtlen += 2;
		}
		print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
	}
	if (ftpf->argflag[0] == '-' && ftpf->argflag[4] == '#' &&
			(ftpf->specflag == 'x' || ftpf->specflag == 'X'))
	{
		ftpf->specflag == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ftpf->width -= 2;
		ftpf->fmtlen += 2;
	}
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] != '0')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
}

t_ftpf		*print_x(t_ftpf *ftpf)
{
	char		*print;

	print = uimaxtoa_base(16, ftpf->uinum, ftpf);
	if (ftpf->prcisn == 0 && ftpf->uinum == 0)
	{
		ft_strclr(print);
		print = NULL;
	}
	else
	{
		ftpf->printlen = ft_strlen(print);
		print = check_prcisn(ftpf, print);
		if (ftpf->argflag[4] == '#' && ftpf->uinum != 0 &&
				ftpf->argflag[3] != '0' && ftpf->argflag[0] != '-')
		{
			if (ftpf->specflag == 'x')
				print = strfree("0x", print, 2);
			else if (ftpf->specflag == 'X')
				print = strfree("0X", print, 2);
			ftpf->fmtlen += 2;
			ftpf->printlen += 2;
		}
	}
	ui_arg(ftpf, print);
	return (ftpf);
}

t_ftpf		*print_o(t_ftpf *ftpf)
{
	char		*print;

	print = uimaxtoa_base(8, ftpf->uinum, ftpf);
	if (ftpf->argflag[4] == '#')
	{
		if (ftpf->uinum == 0 && ftpf->prcisn <= 1)
		{
			ft_strclr(print);
			print = ft_strnew(1);
			print = "0";
		}
		else
			print = strfree("0", print, 2);
	}
	ftpf->printlen = ft_strlen(print);
	if (ftpf->prcisn == 0 && ftpf->uinum == 0 && ftpf->argflag[4] != '#')
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	print = check_prcisn(ftpf, print);
	ui_arg(ftpf, print);
	return (ftpf);
}

uintptr_t	check_uiconv(t_ftpf *ftpf)
{
	uintptr_t	num;

	if (ft_strcmp(ftpf->cnvrsn, "hh") == 1)
		num = (unsigned char)va_arg(ftpf->ap, unsigned int);
	else if (ft_strcmp(ftpf->cnvrsn, "h") == 0)
		num = (unsigned short)va_arg(ftpf->ap, unsigned int);
	else if (ft_strcmp(ftpf->cnvrsn, "l") == 0)
		num = (unsigned long)va_arg(ftpf->ap, void *);
	else if (ft_strcmp(ftpf->cnvrsn, "ll") == 1)
		num = (unsigned long long)va_arg(ftpf->ap, void *);
	else
		num = va_arg(ftpf->ap, unsigned int);
	num = (uintptr_t)num;
	if (num == 0 && ftpf->argflag[4] == '#' && (ftpf->specflag == 'x' ||
			ftpf->specflag == 'X'))
		ftpf->argflag[4] = '\0';
	return (num);
}

t_ftpf		*print_ui(t_ftpf *ftpf)
{
	char		*print;

	ftpf->uinum = check_uiconv(ftpf);
	print = 0;
	if (ftpf->specflag == 'u')
	{
		print = uimaxtoa_base(10, ftpf->uinum, ftpf);
		ftpf->printlen = ft_strlen(print);
		if (ftpf->prcisn <= 0 && ftpf->uinum == 0)
		{
			ft_strclr(print);
			print = NULL;
			ftpf->printlen = 0;
		}
		print = check_prcisn(ftpf, print);
		ui_arg(ftpf, print);
	}
	else if (ftpf->specflag == 'o')
		print_o(ftpf);
	else if (ftpf->specflag == 'x' || ftpf->specflag == 'X')
		print_x(ftpf);
	return (ftpf);
}
