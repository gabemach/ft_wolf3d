/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:23:59 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/24 12:36:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <ctype.h>
# include "../libft/libft.h"

typedef struct		s_ftpf
{
	char			*spec;
	char			*conv;
	char			*arg;
	void			*print;
	va_list			ap;
	const char		*fmt;
	char			*fmtcpy;
	int				fmtlen;
	int				printlen;
	char			*fmttreat;
	size_t			i;
	char			specflag;
	char			argflag[5];
	char			cnvrsn[2];
	long int		prcisn;
	long int		width;
	intptr_t		sinum;
	uintptr_t		uinum;
	char			*string;
}					t_ftpf;

int					ft_printf(const char *fmt, ...);
char				*simaxtoa_base(int base, intptr_t num);
char				*uimaxtoa_base(int base, uintptr_t num, t_ftpf *ftpf);

t_ftpf				*parse_arg(t_ftpf *ftpf);
t_ftpf				*parse_cnvrsn(t_ftpf *ftpf);
t_ftpf				*parse_width(t_ftpf *ftpf);
t_ftpf				*parse_prcisn(t_ftpf *ftpf);
t_ftpf				*parse_spec(t_ftpf *ftpf);
t_ftpf				*swap_print(t_ftpf *ftpf);

void				reinitialize(t_ftpf *ftpf);
void				initialize(t_ftpf *ftpf);

void				print_c(t_ftpf *ftpf);
t_ftpf				*print_s(t_ftpf *ftpf);
t_ftpf				*print_pct(t_ftpf *ftpf);
t_ftpf				*print_si(t_ftpf *ftpf);
t_ftpf				*print_ui(t_ftpf *ftpf);
t_ftpf				*print_p(t_ftpf *ftpf);
t_ftpf				*print_float(t_ftpf *ftpf);
t_ftpf				*print_binary(t_ftpf *ftpf);
t_ftpf				*print_n(t_ftpf *ftpf);
void				print_arg(t_ftpf *ftpf, char c, int len, int new_len);

int					simax_len(int base, intptr_t num);
char				*check_prcisn(t_ftpf *ftpf, char *print);
char				*print_prcisn(t_ftpf *ftpf, char *print);
void				check_arg(t_ftpf *ftpf, char *print);
char				*ftoa(long double num, t_ftpf *ftpf);
char				*strfree(char *s1, char *s2, int flag);
void				set_ui(t_ftpf *ftpf);
void				print_string(t_ftpf *ftpf, int len);
void				print_sign(t_ftpf *ftpf);
uintptr_t			check_uiconv(t_ftpf *ftpf);
intptr_t			check_siconv(t_ftpf *ftps);

#endif