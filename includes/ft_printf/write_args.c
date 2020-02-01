/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:42:55 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/22 14:37:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(t_ftpf *ftpf, char *print)
{
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] == '0')
		print_arg(ftpf, '0', ftpf->width - ftpf->printlen, 1);
	if (ftpf->argflag[0] != '-' && ftpf->argflag[3] != '0')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
	ft_putstr(print);
	if (ftpf->argflag[0] == '-')
		print_arg(ftpf, ' ', ftpf->width - ftpf->printlen, 1);
}

void	print_arg(t_ftpf *ftpf, char c, int len, int new_len)
{
	char	*str;

	if (len > 0)
	{
		if (new_len)
			ftpf->fmtlen += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}
