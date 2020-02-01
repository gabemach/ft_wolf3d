/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:50:48 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/24 18:33:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// void    movement(t_mlx *mlx, int key)
// {
//     if (key == 126)
//     {
//         mlx->posx += mlx->dirx * .1;
//         mlx->posy += mlx->diry * .1;
//     }
//     if (key == 125)
//     {
//         mlx->posx -= mlx->dirx * .1;
//         mlx->posy -= mlx->diry * .1;
//     }
//     // if (key == 123)
//     // {

//     // }
//     mlx_clear_window(mlx->mp, mlx->wp); 
//     mlx_mapping(mlx);
//     //movement(mlx, key);
// }

// int key_hooks(int key, t_mlx *mlx)
// {
//     if (key == 126 || key == 125 || key == 124 || key == 123)
//         movement(mlx, key);
//     if (key == 53)
//         exit (0);
//     return (0);
// }

void    forward_back(t_map *map, SDL_Renderer *rend)
{
    if (map->state[SDL_SCANCODE_W])
    {
        if (map->map[(int)(map->posx + map->dirx * .05)][(int)map->posy] <= 0)
            map->posx += map->dirx * .05;
        if (map->map[(int)map->posx][(int)(map->posy + map->diry * .05)] <= 0)
            map->posy += map->diry * .05;
    }
    if (map->state[SDL_SCANCODE_S])
    {
        if (map->map[(int)(map->posx - map->dirx * .05)][(int)map->posy] <= 0)
            map->posx -= map->dirx * .05;
        if (map->map[(int)map->posx][(int)(map->posy - map->diry * .05)] <= 0)
            map->posy -= map->diry * .05;
    }
    mapping(map, rend);
}

void    strafing(t_map *map, SDL_Renderer *rend)
{
    if (map->state[SDL_SCANCODE_A])
    {
        if (map->map[(int)(map->posx - map->planex * .05)][(int)map->posy] <= 0)
            map->posx -= map->planex * .05;
        if (map->map[(int)map->posx][(int)(map->posy - map->planey * .05)] <= 0)
            map->posy -= map->planey * .05;
    }
    if (map->state[SDL_SCANCODE_D])
    {
        if (map->map[(int)(map->posx + map->planex * .05)][(int)map->posy] <= 0)
            map->posx += map->planex * .05;
        if (map->map[(int)map->posx][(int)(map->posy + map->planey * .05)] <= 0)
            map->posy += map->planey * .05;
    }
    mapping(map, rend);
}

void    movement(t_map *map, SDL_Renderer *rend)
{
    if (map->state[SDL_SCANCODE_W] || map->state[SDL_SCANCODE_S])
        forward_back(map, rend);
    if (map->state[SDL_SCANCODE_A] || map->state[SDL_SCANCODE_D])
        strafing(map, rend);
}

void    rotation(t_map *map, SDL_Renderer *rend)
{
    if (map->state[SDL_SCANCODE_E])
    {
        map->olddirx = map->dirx;
        map->dirx = map->dirx * cosf(-.05) - map->diry * sinf(-.05);
        map->diry = map->olddirx * sinf(-.05) + map->diry * cos(-.05);
        map->oldplanex = map->planex;
        map->planex = map->planex * cosf(-.05) - map->planey * sinf(-.05);
        map->planey = map->oldplanex * sinf(-.05) + map->planey * cosf(-.05);
    }
    if (map->state[SDL_SCANCODE_Q])
    {
        map->olddirx = map->dirx;
        map->dirx = map->dirx * cosf(.05) - map->diry * sinf(.05);
        map->diry = map->olddirx * sinf(.05) + map->diry * cosf(.05);
        map->oldplanex = map->planex;
        map->planex = map->planex * cosf(.05) - map->planey * sinf(.05);
        map->planey = map->oldplanex * sinf(.05) + map->planey * cosf(.05);
    }
    mapping(map, rend);
}

void    events(SDL_Event *event, t_map *map, SDL_Renderer *rend)
{
    map->state = SDL_GetKeyboardState(NULL);
    if (map->state[SDL_SCANCODE_W] || map->state[SDL_SCANCODE_S] ||
        map->state[SDL_SCANCODE_A] || map->state[SDL_SCANCODE_D])
        movement(map, rend);
    if (map->state[SDL_SCANCODE_Q] || map->state[SDL_SCANCODE_E])
        rotation(map, rend);
    if (event->type == SDL_QUIT || map->state[SDL_SCANCODE_ESCAPE])
        map->quit = 1;
}