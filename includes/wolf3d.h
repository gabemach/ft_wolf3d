/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:24:22 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/11 10:36:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_timer.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_wall
{
	double		wallx;
	double		step;
	double		texpos;
	int			texx;
	int			texy;
}				t_wall;

typedef struct	s_floor
{
	float		raydirx0;
	float		raydirx1;
	float		raydiry0;
	float		raydiry1;
	int			p;
	float		posz;
	float		rowdist;
	float		stepx;
	float		stepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	int			ftex;
	int			ctex;
	int			x;
	int			y;
}				t_floor;

typedef struct	s_algo
{
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			contact;
}				t_algo;

typedef struct	s_read
{
	char		**temp;
	int			fd;
	int			t;
	int			x;
	int			y;
}				t_read;

typedef struct	s_screen
{
	SDL_Texture	*view;
	void		*data;
	int			pitch;
	Uint32		*pixel;
}				t_screen;

typedef struct	s_map
{
	int			**map;
	int			x;
	int			y;
	int			border;
	double		posx;
	double		posy;
	double		dirx;
	double		olddirx;
	double		diry;
	double		olddiry;
	double		planex;
	double		oldplanex;
	double		planey;
	double		oldplaney;
	const Uint8	*state;
	int			quit;
	SDL_Surface	*textures[8];
	Uint32		*pixel;
	int			texnum;
	t_screen	*screen;
	SDL_Event	event;
	int			pause;
}				t_map;

void			mapping(t_map *map, SDL_Renderer *rend);
void			init_maths(t_map map, char *av);
void			assign_textures(SDL_Window *win, SDL_Renderer *rend,
					t_map *map);
void			find_contact(t_map *map, t_algo *algo);
void			init_rays(t_map *map, t_algo *algo, int x);
void			set_steps(t_map *map, t_algo *algo);
void			dda_algo(t_map *map, t_algo *algo);
void			find_start(t_map *map);
void			readmap(char *av, t_map *map);
void			events(SDL_Event *event, t_map *map, SDL_Renderer *rend);
void			init_map(t_map *map, char *av);
SDL_Window		*init_win(char *name);
SDL_Surface		*init_surface(SDL_Window *win);
SDL_Renderer	*init_renderer(SDL_Window *win);
void			texture_line(t_map *map, t_algo *algo, int x,
					SDL_Renderer *rend);
void			c_f_calcs1(t_map *map, t_floor *floor);
void			c_f_calcs2(t_map *map, t_floor *floor);
void			free_all(t_map *map, SDL_Window *win, SDL_Renderer *rend);
void			play_music(t_map *map);
void			input_number(t_map *map, t_read *read);
void			movement(t_map *map, SDL_Renderer *rend);
void			rotation(t_map *map, SDL_Renderer *rend);

# define HEIGHT 480
# define WIDTH 640
# define TEXHEIGHT 64
# define TEXWIDTH 64

#endif
