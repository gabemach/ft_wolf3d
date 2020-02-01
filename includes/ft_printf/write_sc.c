/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:21:58 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:28:23 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_string(t_ftpf *ftpf)
{
	ftpf->string = "(null)";
	if (ftpf->prcisn > -1 && ftpf->string)
		ftpf->string = ft_strndup(ftpf->string, ftpf->prcisn);
	ftpf->printlen = ft_strlen(ftpf->string);
	ftpf->fmtlen += ftpf->printlen;
	print_string(ftpf, ftpf->printlen);
}

void	print_string(t_ftpf *ftpf, int len)
{
	if (ftpf->argflag[3] == '0' && ftpf->argflag[0] != '-')
		print_arg(ftpf, '0', ftpf->width - len, 1);
	else if (ftpf->argflag[0] != '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
	ft_putstr(ftpf->string);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
}

void	print_c(t_ftpf *ftpf)
{
	int		c;

	c = (int)va_arg(ftpf->ap, int);
	ftpf->fmtlen += 1;
	if (ftpf->argflag[3] == '0' && ftpf->argflag[0] != '-')
		print_arg(ftpf, '0', ftpf->width - 1, 1);
	else if (ftpf->argflag[0] != '-')
		print_arg(ftpf, ' ', ftpf->width - 1, 1);
	ft_putchar(c);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - 1, 1);
}

t_ftpf	*print_s(t_ftpf *ftpf)
{
	ftpf->string = va_arg(ftpf->ap, char *);
	if (ftpf->string == NULL)
	{
		null_string(ftpf);
		return (ftpf);
	}
	else
	{
		if (ftpf->prcisn > -1 && ftpf->string)
			ftpf->string = ft_strndup(ftpf->string, ftpf->prcisn);
		ftpf->printlen = ft_strlen(ftpf->string);
		ftpf->fmtlen += ftpf->printlen;
		print_string(ftpf, ftpf->printlen);
		return (ftpf);
	}
}
