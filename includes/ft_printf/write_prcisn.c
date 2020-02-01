/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_prcisn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:38:16 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/18 16:12:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_prcisn(t_ftpf *ftpf, char *print)
{
	if (ftpf->prcisn <= ftpf->printlen)
		ftpf->fmtlen += ftpf->printlen;
	else
		print = print_prcisn(ftpf, print);
	return (print);
}

char	*print_prcisn(t_ftpf *ftpf, char *print)
{
	char	*str;

	if (ftpf->prcisn > ftpf->printlen && print)
	{
		str = ft_strnew(ftpf->prcisn - ftpf->printlen);
		ft_memset(str, '0', ftpf->prcisn - ftpf->printlen);
		print = strfree(str, print, 2);
		ftpf->printlen = ft_strlen(print);
		ftpf->fmtlen += ftpf->printlen;
		free(str);
	}
	else if (ftpf->prcisn == -1 && !print)
		print = ft_strndup("(null)", ftpf->prcisn);
	else if (ftpf->prcisn > -1 && !print)
		print = ft_strndup("(null)", ftpf->prcisn);
	else if (ftpf->prcisn == -1 && !print)
		print = ft_strdup("(null)");
	return (print);
}
