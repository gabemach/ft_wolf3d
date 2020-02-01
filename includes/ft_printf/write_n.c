/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:07:17 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 18:26:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftpf	*print_n(t_ftpf *ftpf)
{
	char	*print;

	ftpf->sinum = ftpf->fmtlen;
	print = simaxtoa_base(10, ftpf->sinum);
	ftpf->printlen = ft_strlen(print);
	ft_putstr(print);
	ftpf->fmtlen += ftpf->printlen;
	return (ftpf);
}
