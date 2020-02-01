/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:02:14 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/17 13:41:57 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_ftpf	*parse_arg(t_ftpf *ftpf)
{
	size_t	i;

	i = 0;
	while (ftpf->arg[i] != '\0')
	{
		while (ftpf->arg[i] == ftpf->fmttreat[ftpf->i])
		{
			while (ftpf->fmttreat[ftpf->i] == '-' && ftpf->i++)
				ftpf->argflag[0] = '-';
			while (ftpf->fmttreat[ftpf->i] == '+' && ftpf->i++)
				ftpf->argflag[1] = '+';
			while (ftpf->fmttreat[ftpf->i] == ' ' && ftpf->i++)
				ftpf->argflag[2] = ' ';
			while (ftpf->fmttreat[ftpf->i] == '0' && ftpf->i++)
				ftpf->argflag[3] = '0';
			while (ftpf->fmttreat[ftpf->i] == '#' && ftpf->i++)
				ftpf->argflag[4] = '#';
		}
		i++;
	}
	return (ftpf);
}

t_ftpf	*parse_cnvrsn(t_ftpf *ftpf)
{
	int		i;
	int		j;

	i = 0;
	while (ftpf->conv[i] != '\0')
	{
		j = 0;
		while (ftpf->conv[i] == ftpf->fmttreat[ftpf->i])
		{
			ftpf->cnvrsn[j] = ftpf->fmttreat[ftpf->i];
			ftpf->cnvrsn[j + 1] = '\0';
			ftpf->i++;
			j++;
		}
		i++;
	}
	return (ftpf);
}

t_ftpf	*parse_width(t_ftpf *ftpf)
{
	if (ftpf->fmttreat[ftpf->i] == '*')
	{
		ftpf->width = (long int)va_arg(ftpf->ap, long int);
		ftpf->i++;
	}
	else
	{
		while (ftpf->fmttreat[ftpf->i] >= '0' && ftpf->fmttreat[ftpf->i] <= '9')
		{
			ftpf->width *= 10;
			ftpf->width += (ftpf->fmttreat[ftpf->i] - 48);
			ftpf->i++;
		}
	}
	return (ftpf);
}

t_ftpf	*parse_prcisn(t_ftpf *ftpf)
{
	if (ftpf->fmttreat[ftpf->i] == '.')
	{
		ftpf->i++;
		ftpf->prcisn = 0;
	}
	if (ftpf->fmttreat[ftpf->i] == '*')
	{
		ftpf->prcisn = (long int)va_arg(ftpf->ap, long int);
		ftpf->i++;
	}
	else
	{
		while (ftpf->fmttreat[ftpf->i] >= '0' && ftpf->fmttreat[ftpf->i] <= '9')
		{
			ftpf->prcisn *= 10;
			ftpf->prcisn += (ftpf->fmttreat[ftpf->i] - 48);
			ftpf->i++;
		}
	}
	return (ftpf);
}

t_ftpf	*parse_spec(t_ftpf *ftpf)
{
	size_t	i;

	i = 0;
	while (ftpf->spec[i] != '\0')
	{
		if (ftpf->spec[i] == ftpf->fmttreat[ftpf->i])
			ftpf->specflag = ftpf->spec[i];
		i++;
	}
	return (ftpf);
}
