/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:39:42 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:30:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf	*print_binary(t_ftpf *ftpf)
{
	char	*print;

	if (ftpf->prcisn < 0)
		ftpf->uinum = check_uiconv(ftpf);
	print = uimaxtoa_base(2, ftpf->uinum, ftpf);
	ftpf->printlen = ft_strlen(print);
	if (ftpf->prcisn == 0 && ftpf->uinum == 0)
	{
		ft_strclr(print);
		print = NULL;
		ftpf->printlen = 0;
	}
	if (ftpf->prcisn <= ftpf->printlen)
		ftpf->fmtlen += ftpf->printlen;
	else
		print = check_prcisn(ftpf, print);
	check_arg(ftpf, print);
	return (ftpf);
}
