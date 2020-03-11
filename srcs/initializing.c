/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:31:12 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/04 18:11:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			input_number(t_map *map, t_read *read)
{
	map->map[read->y][read->x] = ft_atoi(read->temp[read->x]);
	if (map->map[read->y][read->x] > 8)
		ft_puterr("Invalid Cell Number");
}

void			free_all(t_map *map, SDL_Window *win, SDL_Renderer *rend)
{
	free(map);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
}

void			init_map(t_map *map, char *av)
{
	readmap(av, map);
	map->dirx = -1;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0.66;
	map->quit = 0;
	map->pause = 0;
}

/*
**	Initializes Window
*/

SDL_Window		*init_win(char *name)
{
	SDL_Window		*win;

	win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
		SDL_Quit();
	return (win);
}

SDL_Renderer	*init_renderer(SDL_Window *win)
{
	SDL_Renderer	*rend;

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED |
	SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(rend, 169, 169, 169, 255);
	SDL_RenderClear(rend);
	SDL_RenderPresent(rend);
	return (rend);
}
