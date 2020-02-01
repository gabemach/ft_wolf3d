/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:06:32 by gmachado          #+#    #+#             */
/*   Updated: 2019/02/22 16:36:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_reader(char **s, char **line, int fd, int out)
{
	char	*temp;
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		temp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = temp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (out == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *s[4864];
	char		buf[BUFF_SIZE + 1];
	char		*loc;
	int			out;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((out = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[out] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		loc = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = loc;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (out < 0)
		return (-1);
	else if (out == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (line_reader(s, line, fd, out));
}
