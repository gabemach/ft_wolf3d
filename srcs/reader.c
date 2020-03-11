/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:41:22 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/10 10:47:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	reset_map(t_map *map)
{
	int				x;
	int				y;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == 9)
				map->map[y][x] = 0;
		}
	}
}

void	validate_map(t_map *map, int x, int y)
{
	static int		target;
	static int		change;

	target = 0;
	change = 9;
	if (map->map[y][x] != target)
		return ;
	if ((x == 0 && map->map[y][x] == 0) ||
		(x == map->x - 1 && map->map[y][x] == 0) ||
		(y == 0 && map->map[y][x] == 0) ||
		(y == map->y - 1 && map->map[y][x] == 0))
		ft_puterr("Invalid Map: Incomplete Border");
	map->map[y][x] = change;
	validate_map(map, x + 1, y);
	validate_map(map, x - 1, y);
	validate_map(map, x, y + 1);
	validate_map(map, x, y - 1);
	return ;
}

void	fill_map(char *av, char *line, t_map *map, t_read *read)
{
	free(read->temp);
	read->fd = open(av, O_RDONLY);
	read->y = 0;
	while (get_next_line(read->fd, &line) > 0)
	{
		read->temp = ft_strsplit(line, ' ');
		free(line);
		read->x = -1;
		while (read->temp[++read->x])
			input_number(map, read);
		read->x != map->x ? ft_puterr("Invalid Map: Map is not rectangular.") :
			0;
		read->y++;
		read->x = -1;
		while (read->temp[++read->x])
			free(read->temp[read->x]);
		free(read->temp);
	}
	close(read->fd);
	find_start(map);
	map->map[map->posy][map->posx] = 0;
	validate_map(map, map->posx, map->posy);
	reset_map(map);
}

void	check_input(char *av, t_read *read)
{
	if ((read->fd = open(av, O_DIRECTORY)) > 0)
		ft_puterr("Error: Input is a directory.");
	if ((read->fd = open(av, O_RDONLY)) < 0)
		ft_puterr("Error: Invalid File.");
}

void	readmap(char *av, t_map *map)
{
	t_read			read;
	char			*line;

	read.t = -1;
	map->x = 0;
	check_input(av, &read);
	if (get_next_line(read.fd, &line))
	{
		read.temp = ft_strsplit(line, ' ');
		free(line);
		while (read.temp[map->x])
			free(read.temp[map->x++]);
		map->y = 1;
		while ((get_next_line(read.fd, &line) > 0) && map->y++)
			free(line);
		map->map = (int **)ft_memalloc(sizeof(int *) * map->y);
		while (++read.t < map->y)
			map->map[read.t] = (int *)ft_memalloc(sizeof(int) * map->x);
		close(read.fd);
		fill_map(av, line, map, &read);
	}
	else
		ft_puterr("This shit empty! YEET!");
}
