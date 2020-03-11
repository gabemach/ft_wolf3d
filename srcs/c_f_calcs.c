/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_f_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:25:44 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/03 19:14:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	c_f_calcs2(t_map *map, t_floor *floor)
{
	floor->cellx = (int)floor->floorx;
	floor->celly = (int)floor->floory;
	floor->tx = (int)(TEXWIDTH * (floor->floorx - floor->cellx))
		& (TEXWIDTH - 1);
	floor->ty = (int)(TEXHEIGHT * (floor->floory - floor->celly))
		& (TEXHEIGHT - 1);
	floor->floorx += floor->stepx;
	floor->floory += floor->stepy;
}

void	c_f_calcs1(t_map *map, t_floor *floor)
{
	floor->raydirx0 = map->dirx - map->planex;
	floor->raydiry0 = map->diry - map->planey;
	floor->raydirx1 = map->dirx + map->planex;
	floor->raydiry1 = map->diry + map->planey;
	floor->p = floor->y - HEIGHT / 2;
	floor->posz = 0.5 * HEIGHT;
	floor->rowdist = floor->posz / floor->p;
	floor->stepx = floor->rowdist *
		(floor->raydirx1 - floor->raydirx0) / WIDTH;
	floor->stepy = floor->rowdist *
		(floor->raydiry1 - floor->raydiry0) / WIDTH;
	floor->floorx = map->posx + floor->rowdist * floor->raydirx0;
	floor->floory = map->posy + floor->rowdist * floor->raydiry0;
}
