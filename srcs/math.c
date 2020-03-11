/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:18:53 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/11 13:29:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	dda_algo(t_map *map, t_algo *algo)
{
	if (map->border == 0)
		algo->perpwalldist = (algo->mapx - map->posx + (1 - algo->stepx) / 2) /
			algo->raydirx;
	else
		algo->perpwalldist = (algo->mapy - map->posy + (1 - algo->stepy) / 2) /
			algo->raydiry;
	algo->perpwalldist <= .01 ? algo->perpwalldist += .01 : 0;
	algo->lineheight = (int)(HEIGHT / algo->perpwalldist);
	algo->drawstart = -(algo->lineheight) / 2 + (HEIGHT / 2);
	if (algo->drawstart < 0)
		algo->drawstart = 0;
	algo->drawend = algo->lineheight / 2 + HEIGHT / 2;
	if (algo->drawend >= HEIGHT)
		algo->drawend = HEIGHT - 1;
}

void	init_rays(t_map *map, t_algo *algo, int x)
{
	algo->camerax = 2 * x / (double)WIDTH - 1;
	algo->raydirx = map->dirx + map->planex * algo->camerax;
	algo->raydiry = map->diry + map->planey * algo->camerax;
	algo->mapx = (int)map->posx;
	algo->mapy = (int)map->posy;
	algo->deltadistx = fabs(1 / algo->raydirx);
	algo->deltadisty = fabs(1 / algo->raydiry);
	map->border = 0;
}

void	find_contact(t_map *map, t_algo *algo)
{
	while (algo->contact == 0)
	{
		if (algo->sidedistx < algo->sidedisty)
		{
			algo->sidedistx += algo->deltadistx;
			algo->mapx += algo->stepx;
			map->border = 0;
		}
		else
		{
			algo->sidedisty += algo->deltadisty;
			algo->mapy += algo->stepy;
			map->border = 1;
		}
		if (map->map[algo->mapx][algo->mapy] > 0)
		{
			algo->contact = 1;
			map->texnum = map->map[algo->mapx][algo->mapy] - 1;
		}
		else
			map->texnum = NULL;
	}
}

void	set_steps(t_map *map, t_algo *algo)
{
	if (algo->raydirx < 0)
	{
		algo->stepx = -1;
		algo->sidedistx = (map->posx - algo->mapx) * algo->deltadistx;
	}
	else
	{
		algo->stepx = 1;
		algo->sidedistx = (algo->mapx + 1.0 - map->posx) * algo->deltadistx;
	}
	if (algo->raydiry < 0)
	{
		algo->stepy = -1;
		algo->sidedisty = (map->posy - algo->mapy) * algo->deltadisty;
	}
	else
	{
		algo->stepy = 1;
		algo->sidedisty = (algo->mapy + 1.0 - map->posy) * algo->deltadisty;
	}
}
