/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:39:09 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/04 18:41:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

/*
**	Initializes Textures
*/

SDL_Surface	*init_texture(SDL_Window *win, char *img_path)
{
	SDL_Surface		*texture;

	if (!(texture = SDL_LoadBMP(img_path)))
		ft_puterr("Missing Texture!");
	texture = SDL_ConvertSurfaceFormat(texture,
		SDL_GetWindowPixelFormat(win), 0);
	return (texture);
}

void		assign_textures(SDL_Window *win, SDL_Renderer *rend, t_map *map)
{
	int	i;

	i = 0;
	map->screen = ft_memalloc(sizeof(t_screen));
	map->screen->view = SDL_CreateTexture(rend, SDL_GetWindowPixelFormat(win),
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	map->textures[0] = init_texture(win, "./pics/eagle.bmp");
	map->textures[1] = init_texture(win, "./pics/redbrick.bmp");
	map->textures[2] = init_texture(win, "./pics/purplestone.bmp");
	map->textures[3] = init_texture(win, "./pics/greystone.bmp");
	map->textures[4] = init_texture(win, "./pics/bluestone.bmp");
	map->textures[5] = init_texture(win, "./pics/mossy.bmp");
	map->textures[6] = init_texture(win, "./pics/wood.bmp");
	map->textures[7] = init_texture(win, "./pics/colorstone.bmp");
}
