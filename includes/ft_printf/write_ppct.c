/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:14:23 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:29:13 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf	*print_pct(t_ftpf *ftpf)
{
	char		*print;

	print = ft_strnew(1);
	print[0] = '%';
	print = check_prcisn(ftpf, print);
	ftpf->printlen += ft_strlen(print);
	ftpf->fmtlen += ftpf->printlen;
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] != '0')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] == '0')
		print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
	return (ftpf);
}

t_ftpf	*print_p(t_ftpf *ftpf)
{
	char		*print;
	int			len;
	uintptr_t	p;

	p = (uintptr_t)(va_arg(ftpf->ap, void *));
	if (!(ftpf->prcisn <= 0 && p == 0))
	{
		print = uimaxtoa_base(16, p, ftpf);
		print = strfree("0x", print, 2);
	}
	else
		print = "0x";
	len = ft_strlen(print);
	if (ftpf->width && ftpf->argflag[0] != '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - len, 1);
	return (ftpf);
}
