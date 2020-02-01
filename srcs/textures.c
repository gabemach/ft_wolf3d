/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:49:45 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/30 18:12:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

// Uint32      color_pixels(t_map *map, t_algo *algo, t_wall *wall)
// {
//     void    *pixels;
//     int     pitch;

//     pixels = NULL;
//     pitch = 0;
//     SDL_LockTexture(map->textures[map->texnum], NULL, &pixels, &pitch);
//     map->pixel = (Uint32 *)pixels;
    
// }

// void        texture_line(t_map *map, t_algo *algo, int x, SDL_Renderer *rend)
// {
//     SDL_Rect        line;
//     void            *pixel;

//     line.x = x;
//     line.y = algo->drawstart;
//     line.w = 1;
//     line.h = algo->drawend;
//     SDL_RenderCopy(rend, map->textures[map->texnum], NULL, &line);
//     SDL_RenderReadPixels(rend, &line, 0, &pixel, WIDTH * 4);
//     SDL_RenderDrawLine(rend, x, algo->drawstart, x, algo->drawend);
// }

// SDL_Texture *resize_texture(SDL_Texture *texture, SDL_Renderer *rend)
// {
//     SDL_Rect    scale;

//     scale.x = 0;
//     scale.y = 0;
//     scale.w = TEXWIDTH;
//     scale.h = TEXHEIGHT;
//     SDL_RenderCopy(rend, texture, NULL, &scale);
//     return (texture);
// }

/*
**  Initializes Textures
*/

SDL_Surface *init_texture(SDL_Window *win, char *img_path)
{
    SDL_Surface     *texture;

    if (!(texture = SDL_LoadBMP(img_path)))
        return (NULL);
    texture = SDL_ConvertSurfaceFormat(texture,
        SDL_GetWindowPixelFormat(win), 0);
    return (texture);
}

void        assign_textures(SDL_Window *win, SDL_Renderer *rend, t_map *map)
{
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
    //printf("%s\n", "Texture assigned");
}