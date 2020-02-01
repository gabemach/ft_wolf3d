/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:45:16 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/31 19:34:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

Uint32    get_pixel(t_map *map, t_algo *algo)
{
    t_wall  wall;
    Uint32  *pixel;

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
        return (pixel[(wall.texx + wall.texy * (map->textures[map->texnum]->pitch / 4))]);
    else
        return (pixel[(wall.texx + wall.texy * (map->textures[map->texnum]->pitch / 4))] >> 1 & 8355711);
}

// void    draw_floor(t_map *map, t_algo *algo, SDL_Renderer *rend)
// {
//     t_floor floor;
//     int     y;
//     int     x;

//     y = -1;
//     while (++y < HEIGHT)
//     {
//         floor.raydirx0 = map->dirx - map->planex;
//         floor.raydiry0 = map->diry - map->planey;
//         floor.raydirx1 = map->dirx + map->planex;
//         floor.raydiry1 = map->diry + map->planey;
//         floor.p = y - HEIGHT / 2;
//         floor.posz = 0.5 * HEIGHT;
//         floor.rowdist = floor.posz / floor.p;
//         floor.stepx = floor.rowdist * (floor.raydirx1 - floor.raydirx0) / WIDTH;
//         floor.stepy = floor.rowdist * (floor.raydiry1 - floor.raydiry0) / WIDTH;
//         floor.floorx = map->posx + floor.rowdist * floor.raydirx0;
//         floor.floory = map->posy + floor.rowdist * floor.raydiry0;
//         x = -1;
//         while (++x < WIDTH)
//         {
//             floor.cellx = (int)floor.floorx;
//             floor.celly = (int)floor.floory;
//             floor.tx = (int)(TEXWIDTH * (floor.floorx - floor.cellx)) & (TEXWIDTH - 1);
//             floor.ty = (int)(TEXHEIGHT * (floor.floory - floor.celly)) & (TEXHEIGHT -1);
//             floor.floorx += floor.stepx;
//             floor.floory += floor.stepy;
//             floor.floortex = 3;
//             floor.ceilingtex = 6;
//             SDL_SetRenderTarget(rend, map->textures[floor.floortex]);
//             SDL_RenderDrawPoint(rend, x, y);
//             SDL_SetRenderTarget(rend, map->textures[floor.ceilingtex]);
//             SDL_RenderDrawPoint(rend, x, HEIGHT - y - 1);
//         }
//     }
// }

void    draw_lines(t_map *map, t_algo *algo, SDL_Renderer *rend, int x)
{
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, x, 0, x, algo->drawstart);
    if (map->border == 1)
        SDL_SetRenderDrawColor(rend, 0, 255 / 2, 0, 255);
    else
        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
    SDL_RenderDrawLine(rend, x, algo->drawstart, x, algo->drawend);
    SDL_SetRenderDrawColor(rend, 169, 169, 169, 255);
    SDL_RenderDrawLine(rend, x, algo->drawend, x, HEIGHT + 1);
}

void    find_start(t_map *map)
{
    int x;
    int y;

    y = -1;
    while (++y < map->y)
    {
        x = -1;
        while (++x < map->x)
        {
            if (map->map[y][x] == -1)
            {
                map->posx = y;
                map->posy = x;
            }
        }
    }
    if (!(map->posx) && !(map->posy))
    {
        ft_putendl("Starting position not found!");
        exit (1);
    }
}

void    mapping(t_map *map, SDL_Renderer *rend)
{
    int x;
    t_algo  algo;

    SDL_LockTexture(map->screen->view, NULL, &map->screen->data,
        &map->screen->pitch);
    map->screen->pixel = (Uint32 *)map->screen->data;
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
            map->screen->pixel[x + algo.drawstart *
                (map->screen->pitch / 4)] = get_pixel(map, &algo);
            algo.drawstart++;
        }
    }
    SDL_UnlockTexture(map->screen->view);
    SDL_RenderCopy(rend, map->screen->view, NULL, NULL);
    SDL_RenderPresent(rend);
}

// void    set_lines(t_mlx *mlx, t_algo *algo, int x)
// {
//     int y;

//     y = 0;
//     while (y < algo->drawstart)
//     {
//         mlx->color = 65536 * 100;
//         ((unsigned int *)mlx->addr)[x + (WIDTH * y)] = mlx->color;
//         y++;
//     }
//     while (y < algo->drawend)
//     {
//         // if (mlx->map[y][x] == 1)
//         //     mlx->color = 65536 * 255;
//         // if (mlx->map[y][x] == 2)
//         //     mlx->color = 256 * 255;
//         // if (mlx->map[y][x] == 3)
//         //     mlx->color = 255;
//         // if (mlx->map[y][x] == 4)
//         //     mlx->color = 65536 * 66 + 256 * 30 + 15;
//         // if (border == 1)
//         //     mlx->color /= 2;
//         mlx->color = 255;
//         if (mlx->border == 1)
//             mlx->color /= 2;
//         ((unsigned int *)mlx->addr)[x + (WIDTH * y)] = mlx->color;
//         y++;
//     }
//     while (y < HEIGHT)
//     {
//         mlx->color = 65536 * 125;
//         ((unsigned int *)mlx->addr)[x + (WIDTH * y)] = mlx->color;
//         y++;
//     }
// }

// void    mlx_mapping(t_mlx *mlx)
// {
//     int x;
//     t_algo  algo;

//     x = -1;
//     while (++x < WIDTH)
//     {
//         algo.contact = 0;
//         algo.camerax = 2 * x / (double)WIDTH - 1;
//         algo.raydirx = mlx->dirx + mlx->planex * algo.camerax;
//         algo.raydiry = mlx->diry + mlx->planey * algo.camerax;
//         algo.mapx = (int)mlx->posx;
//         algo.mapy = (int)mlx->posy;
//         algo.deltadistx = fabs(1 / algo.raydirx);
//         algo.deltadisty = fabs(1 / algo.raydiry);
//         set_steps(mlx, &algo);
//         while (algo.contact == 0)
//         {
//             if (algo.sidedistx < algo.sidedisty)
//             {
//                 algo.sidedistx += algo.deltadistx;
//                 algo.mapx += algo.stepx;
//                 mlx->border = 0;
//             }
//             else
//             {
//                 algo.sidedisty += algo.deltadisty;
//                 algo.mapy += algo.stepy;
//                 mlx->border = 1;
//             }
//             if (mlx->map[algo.mapy][algo.mapx] > 0)
//                 algo.contact = 1;
//         }
//         if (mlx->border == 0)
//             algo.perpwalldist = (algo.mapx - mlx->posx + (1 - algo.stepx) / 2) / algo.raydirx;
//         else
//             algo.perpwalldist = (algo.mapy - mlx->posy + (1 - algo.stepy) / 2) / algo.raydiry;
//         algo.lineheight = (int)(HEIGHT / algo.perpwalldist);
//         algo.drawstart = -(algo.lineheight) / 2 + HEIGHT / 2;
//         if (algo.drawstart < 0)
//             algo.drawstart = 0;
//         algo.drawend = algo.lineheight / 2 + HEIGHT / 2;
//         if (algo.drawend >= HEIGHT)
//             algo.drawend = HEIGHT - 1;
//         set_lines(mlx, &algo, x);
//     }
//     mlx_put_image_to_window(mlx->mp, mlx->wp, mlx->ip, 0, 0);
// }