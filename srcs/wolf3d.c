/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:38:48 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/31 19:47:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void    fill_map(char *av, char **temp, t_map *map, t_read *read)
{
    int x;
    int y;
    char *line;

    y = 0;
    read->fd3 = open(av, O_RDONLY);
    while (get_next_line(read->fd3, &line) > 0)
    {
        x = -1;
        temp = ft_strsplit(line, ' ');
        while (temp[++x])
            map->map[y][x] = ft_atoi(temp[x]);
        x = -1;
        while (temp[++x])
            free(temp[x]);
        free(temp);
        y++;
        free(line);
    }
    close(read->fd3);
}

void    check_map(char *av, t_read *read, t_map *map)
{
    char    *line;
    int     fd;

    fd = open(av, O_DIRECTORY);
    if (fd > 0)
    {
        ft_putendl("Error: av is a directory.");
        exit(0);
    }
    read->fd1 = open(av, O_RDONLY);
    if (read->fd1 < 0)
    {
        ft_putendl("Error: Invalid File.");
        exit(0);
    }
    while (get_next_line(read->fd1, &line) == 1)
    {
        map->y++;
        free(line);
    }
    close(read->fd1);
}

void    readmap(char *av, t_map *map)
{
    t_read  read;
    int     i;
    char    *line;
    char    **temp;

    check_map(av, &read, map);
    read.fd2 = open(av, O_RDONLY);
    get_next_line(read.fd2, &line);
    temp = ft_strsplit(line, ' ');
    free(line);
    while (temp[map->x])
        map->x++;
    i = -1;
    map->map = (int **)ft_memalloc(sizeof(int *) * map->y);
    while (++i < map->y)
        map->map[i] = (int *)ft_memalloc(sizeof(int) * map->x);
    close(read.fd2);
    i = -1;
    while (temp[++i])
        free(temp[i]);
    free(temp);
    fill_map(av, temp, map, &read);
}

void    init_map(t_map *map, char *av)
{
    readmap(av, map);
    find_start(map);
    map->dirx = -1;
    map->diry = 0;
    map->planex = 0;
    map->planey = 0.66;
    map->quit = 0;
}

int main(int ac, char **av)
{
    SDL_Window  *win;
    SDL_Event   event;
    SDL_Renderer    *rend;
    t_map       *map;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        ft_putendl("An error occured initializing SDL.");
    win = init_win("Wolf3d");
    rend = init_renderer(win);
    if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
        exit (0);
    init_map(map, av[1]);
    assign_textures(win, rend, map);
    if (ac > 1)
    {
        mapping(map, rend);
        while (map->quit == 0)
        {
            while (SDL_PollEvent(&event))
                events(&event, map, rend);
            SDL_Delay(90);
        }
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    return (0);

    // t_mlx   mlx;

    // create_win(&mlx);
    // init_map(&mlx, av[1]);
    // //readmap(av[1], &mlx);
    // find_start(&mlx);
    // if (ac > 1)
    // {
    //     if (av[1])
    //     {
    //         mlx_mapping(&mlx);
    //         mlx_key_hook(mlx.wp, key_hooks, &mlx);
    //         mlx_loop(mlx.mp);
    //     }
    // }
    // else
    // {
    //     ft_putendl("Input map");
    //     exit (0);
    // }
}

