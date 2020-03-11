/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:32:57 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/10 10:44:00 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>



Uint32		get_pixel(t_map *map, t_algo *algo)
{
	t_wall	wall;
	Uint32	*pixel;

	if (map->border == 0)
		wall.wallx = map->posy + algo->perpwalldist * algo->raydiry;
	else
		wall.wallx = map->posx + algo->perpwalldist * algo->raydirx;
	wall.wallx -= floor(wall.wallx);
	wall.texx = (int)(wall.wallx * (double)TEXWIDTH);
	if (map->border == 0 && algo->raydirx > 0)
		wall.texx = TEXWIDTH - wall.texx - 1;
	if (map->border == 1 && algo->raydiry <= 0)
		wall.texx = TEXWIDTH - wall.texx - 1;
	wall.texy = (((double)algo->drawstart - (HEIGHT - algo->lineheight) / 2) /
		algo->lineheight * TEXHEIGHT);
	pixel = (Uint32 *)map->textures[map->texnum]->pixels;
	if (map->border == 1)
		return (pixel[(wall.texx + wall.texy *
			(map->textures[map->texnum]->pitch / 4))]);
	else
		return (pixel[(wall.texx + wall.texy *
			(map->textures[map->texnum]->pitch / 4))] >> 1 & 8355711);
}

void		draw_floor(t_map *map)
{
	t_floor floor;
	Uint32	*pixel;

	floor.y = -1;
	while (++floor.y < HEIGHT)
	{
		c_f_calcs1(map, &floor);
		floor.x = -1;
		while (++floor.x < WIDTH)
		{
			c_f_calcs2(map, &floor);
			floor.ftex = 3;
			floor.ctex = 6;
			pixel = (Uint32 *)map->textures[floor.ctex]->pixels;
			map->screen->pixel[floor.x + floor.y * (map->screen->pitch / 4)] =
				pixel[floor.tx + floor.ty *
				(map->textures[floor.ctex]->pitch / 4)];
			pixel = (Uint32 *)map->textures[floor.ftex]->pixels;
			map->screen->pixel[floor.x + (HEIGHT - floor.y - 1) *
				(map->screen->pitch / 4)] =
				pixel[floor.tx + floor.ty *
				(map->textures[floor.ftex]->pitch / 4)] >> 1 & 3618615;
		}
	}
}

void		find_start(t_map *map)
{
	int		x;
	int		y;
	int		error;

	error = 0;
	y = -1;
	while (++y < map->y && error <= 1)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == -1)
			{
				map->posx = x;
				map->posy = y;
				error += 1;
			}
		}
	}
	if (!(map->posx) && !(map->posy))
		ft_puterr("Starting position not found!");
	if (error > 1)
		ft_puterr("Multiple starting points found!");
}

void		mapping(t_map *map, SDL_Renderer *rend)
{
	int		x;
	t_algo	algo;

	SDL_LockTexture(map->screen->view, NULL, &map->screen->data,
		&map->screen->pitch);
	map->screen->pixel = (Uint32 *)map->screen->data;
	draw_floor(map);
	x = -1;
	while (++x < WIDTH)
	{
		algo.contact = 0;
		init_rays(map, &algo, x);
		set_steps(map, &algo);
		find_contact(map, &algo);
		dda_algo(map, &algo);
		while (algo.drawstart < algo.drawend)
		{
			if (map->texnum >= 0)
				map->screen->pixel[x + algo.drawstart *
				(map->screen->pitch / 4)] = get_pixel(map, &algo);
			else
				map->screen->pixel[x + algo.drawstart *
				(map->screen->pitch / 4)] = 0x000000;
			algo.drawstart++;
		}
	}
	SDL_UnlockTexture(map->screen->view);
	SDL_RenderCopy(rend, map->screen->view, NULL, NULL);
	SDL_RenderPresent(rend);
}
