/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:17:48 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/06 15:00:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	forward_back(t_map *map, SDL_Renderer *rend)
{
	if (map->state[SDL_SCANCODE_W])
	{
		if (map->map[(int)(map->posx + map->dirx * .2)][(int)map->posy] <= 0)
			map->posx += map->dirx * .2;
		if (map->map[(int)map->posx][(int)(map->posy + map->diry * .2)] <= 0)
			map->posy += map->diry * .2;
	}
	if (map->state[SDL_SCANCODE_S])
	{
		if (map->map[(int)(map->posx - map->dirx * .2)][(int)map->posy] <= 0)
			map->posx -= map->dirx * .2;
		if (map->map[(int)map->posx][(int)(map->posy - map->diry * .2)] <= 0)
			map->posy -= map->diry * .2;
	}
	mapping(map, rend);
}

void	strafing(t_map *map, SDL_Renderer *rend)
{
	if (map->state[SDL_SCANCODE_A])
	{
		if (map->map[(int)(map->posx - map->planex * .2)][(int)map->posy]
				<= 0)
			map->posx -= map->planex * .2;
		if (map->map[(int)map->posx][(int)(map->posy - map->planey * .2)]
				<= 0)
			map->posy -= map->planey * .2;
	}
	if (map->state[SDL_SCANCODE_D])
	{
		if (map->map[(int)(map->posx + map->planex * .2)][(int)map->posy]
			<= 0)
			map->posx += map->planex * .2;
		if (map->map[(int)map->posx][(int)(map->posy + map->planey * .2)]
			<= 0)
			map->posy += map->planey * .2;
	}
	mapping(map, rend);
}

void	movement(t_map *map, SDL_Renderer *rend)
{
	if (map->state[SDL_SCANCODE_W] || map->state[SDL_SCANCODE_S])
		forward_back(map, rend);
	if (map->state[SDL_SCANCODE_A] || map->state[SDL_SCANCODE_D])
		strafing(map, rend);
}

void	rotation(t_map *map, SDL_Renderer *rend)
{
	if (map->state[SDL_SCANCODE_E])
	{
		map->olddirx = map->dirx;
		map->dirx = map->dirx * cosf(-.15) - map->diry * sinf(-.15);
		map->diry = map->olddirx * sinf(-.15) + map->diry * cos(-.15);
		map->oldplanex = map->planex;
		map->planex = map->planex * cosf(-.15) - map->planey * sinf(-.15);
		map->planey = map->oldplanex * sinf(-.15) + map->planey * cosf(-.15);
	}
	if (map->state[SDL_SCANCODE_Q])
	{
		map->olddirx = map->dirx;
		map->dirx = map->dirx * cosf(.15) - map->diry * sinf(.15);
		map->diry = map->olddirx * sinf(.15) + map->diry * cosf(.15);
		map->oldplanex = map->planex;
		map->planex = map->planex * cosf(.15) - map->planey * sinf(.15);
		map->planey = map->oldplanex * sinf(.15) + map->planey * cosf(.15);
	}
	mapping(map, rend);
}

void	events(SDL_Event *event, t_map *map, SDL_Renderer *rend)
{
	if (event->type == SDL_QUIT || map->state[SDL_SCANCODE_ESCAPE])
	{
		Mix_PauseMusic();
		map->quit = 1;
	}
}
