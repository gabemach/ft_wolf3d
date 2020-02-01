/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:24:22 by gmachado          #+#    #+#             */
/*   Updated: 2020/01/31 19:52:45 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_timer.h"
# include "SDL_ttf.h"
# include "minilibx_macos_sierra/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_wall
{
    double      wallx;
    double      step;
    double      texpos;
    int         texx;
    int         texy;
}               t_wall;

typedef struct  s_floor
{
    float       raydirx0;
    float       raydirx1;
    float       raydiry0;
    float       raydiry1;
    int         p;
    float       posz;
    float       rowdist;
    float       stepx;
    float       stepy;
    float       floorx;
    float       floory;
    int         cellx;
    int         celly;
    int         tx;
    int         ty;
    int         floortex;
    int         ceilingtex;
}               t_floor;

typedef struct  s_algo
{
    double      time;
    double      oldtime;
    int         mapx;
    int         mapy;
    double      sidedistx;
    double      sidedisty;
    double      deltadistx;
    double      deltadisty;
    double      perpwalldist;
    int         stepx;
    int         stepy;
    double      camerax;
    double      raydirx;
    double      raydiry;
    int         lineheight;
    int         drawstart;
    int         drawend;
    int         contact;
}               t_algo;

typedef struct  s_read
{
    int         fd1;
    int         fd2;
    int         fd3;
}               t_read;


typedef struct  s_screen
{
    SDL_Texture *view;
    void        *data;
    int         pitch;
    Uint32      *pixel;
}               t_screen;

typedef struct  s_map
{
    int         **map;
    int         x;
    int         y;
    int         border;
    double      posx;
    double      posy;
    double      dirx;
    double      olddirx;
    double      diry;
    double      olddiry;
    double      planex;
    double      oldplanex;
    double      planey;
    double      oldplaney;
    const Uint8 *state;
    int         quit;
    SDL_Surface *textures[8];
    Uint32      *pixel;
    int         texnum;
    t_screen    *screen;
}               t_map;

typedef struct  s_mlx
{
    void            *mp;
    void            *wp;
    void            *ip;
    char            *addr;
    int             bpp;
    int             sline;
    int             endian;
    int             **map;
    int             x;
    int             y;
    unsigned int    color;
    double          posx;
    double          posy;
    double          dirx;
    double          diry;
    double          planex;
    double          planey;
    int             border;
}               t_mlx;

int     key_hooks(int key, t_mlx *mlx);
void    create_win(t_mlx *mlx);
void    mapping(t_map *map, SDL_Renderer *rend);
void    init_maths(t_map map, char *av);
void    assign_textures(SDL_Window *win, SDL_Renderer *rend, t_map *map);
void    mlx_mapping(t_mlx *mlx);
void    find_contact(t_map *map, t_algo *algo);
void    init_rays(t_map *map, t_algo *algo, int x);
void    set_steps(t_map *map, t_algo *algo);
void    set_lines(t_mlx *mlx, t_algo *algo, int x);
void    dda_algo(t_map *map, t_algo *algo);
void    find_start(t_map *map);
void    readmap(char *av, t_map *map);
void    events(SDL_Event *event, t_map *map, SDL_Renderer *rend);
SDL_Window  *init_win(char *name);
SDL_Surface     *init_surface(SDL_Window *win);
SDL_Renderer    *init_renderer(SDL_Window *win);
void            texture_line(t_map *map, t_algo *algo, int x, SDL_Renderer *rend);

# define HEIGHT 480
# define WIDTH 640
# define TEXHEIGHT 64
# define TEXWIDTH 64

#endif