/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:57:20 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/30 17:44:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
**  Initializes Window
*/

SDL_Window  *init_win(char *name)
{
    SDL_Window  *win;
    
    win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL)
        SDL_Quit();
    return (win);
}

SDL_Renderer    *init_renderer(SDL_Window *win)
{
    SDL_Renderer    *rend;

    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_TARGETTEXTURE);
    SDL_SetRenderDrawColor(rend, 169, 169, 169, 255);
    SDL_RenderClear(rend);
    SDL_RenderPresent(rend);
    return (rend);
}

// void    create_win(t_mlx *mlx)
// {
//     mlx->mp = mlx_init();
//     mlx->wp = mlx_new_window(mlx->mp, WIDTH, HEIGHT, "Wolf3D");
//     mlx->ip = mlx_new_image(mlx->mp, WIDTH, HEIGHT);
//     mlx->bpp = 8;
//     mlx->sline = 1 * WIDTH;
//     mlx->endian = 1;
//     mlx->addr = mlx_get_data_addr(mlx->ip, &mlx->bpp, &mlx->sline,
//                     &mlx->endian);
// }