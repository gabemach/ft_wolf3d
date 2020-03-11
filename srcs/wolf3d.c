/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:19:55 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/06 14:48:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	key_event(t_map *map, SDL_Renderer *rend)
{
	map->state = SDL_GetKeyboardState(NULL);
	play_music(map);
	if (map->state[SDL_SCANCODE_W] || map->state[SDL_SCANCODE_S] ||
		map->state[SDL_SCANCODE_A] || map->state[SDL_SCANCODE_D])
		movement(map, rend);
	if (map->state[SDL_SCANCODE_Q] || map->state[SDL_SCANCODE_E])
		rotation(map, rend);
}

int		main(int ac, char **av)
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	t_map			*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(0);
	init_map(map, av[1]);
	if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO) != 0)
		ft_putendl("An error occured initializing SDL.");
	win = init_win("Wolf3d");
	rend = init_renderer(win);
	Mix_Init(MIX_INIT_OGG);
	assign_textures(win, rend, map);
	mapping(map, rend);
	while (map->quit == 0)
	{
		key_event(map, rend);
		while (SDL_PollEvent(&map->event))
			events(&map->event, map, rend);
		SDL_Delay(90);
	}
	free_all(map, win, rend);
	return (0);
}
