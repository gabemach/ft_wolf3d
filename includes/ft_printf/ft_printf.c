/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:05:26 by gmachado          #+#    #+#             */
/*   Updated: 2019/09/17 16:20:00 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf		*swap_print(t_ftpf *ftpf)
{
	char	*flag;

	flag = &ftpf->specflag;
	if (*flag == 'c')
		print_c(ftpf);
	if (*flag == 's')
		print_s(ftpf);
	if (*flag == 'd' || *flag == 'i')
		print_si(ftpf);
	if (*flag == 'p')
		print_p(ftpf);
	if (*flag == 'u' || *flag == 'o' || *flag == 'x' || *flag == 'X')
	{
		set_ui(ftpf);
		print_ui(ftpf);
	}
	if (*flag == 'f')
		print_float(ftpf);
	if (*flag == 'b')
		print_binary(ftpf);
	if (*flag == '%')
		print_pct(ftpf);
	if (*flag == 'n')
		print_n(ftpf);
	return (ftpf);
}

int			treater(t_ftpf *ftpf)
{
	ftpf->i++;
	parse_arg(ftpf);
	parse_arg(ftpf);
	parse_arg(ftpf);
	parse_width(ftpf);
	parse_prcisn(ftpf);
	parse_cnvrsn(ftpf);
	parse_spec(ftpf);
	if (ftpf->specflag == '\0')
		return (ftpf->fmtlen);
	swap_print(ftpf);
	return (ftpf->fmtlen);
}

int			parser(t_ftpf *ftpf)
{
	while (ftpf->fmtcpy[ftpf->i] != '\0')
	{
		if (ftpf->fmtcpy[ftpf->i] == '%')
		{
			reinitialize(ftpf);
			treater(ftpf);
		}
		else
		{
			ft_putchar(ftpf->fmtcpy[ftpf->i]);
			ftpf->fmtlen++;
		}
		ftpf->i++;
	}
	return (ftpf->fmtlen);
}

int			ft_printf(const char *fmt, ...)
{
	t_ftpf	*ftpf;
	int		fmtlen;

	if (!(ftpf = (t_ftpf*)malloc(sizeof(t_ftpf))))
		return (-1);
	ftpf->fmt = fmt;
	initialize(ftpf);
	if (fmt)
	{
		va_start(ftpf->ap, fmt);
		ftpf->fmtlen = parser(ftpf);
		va_end(ftpf->ap);
	}
	fmtlen = ftpf->fmtlen;
	free(ftpf);
	return (fmtlen);
}
