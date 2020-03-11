/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:21:33 by gmachado          #+#    #+#             */
/*   Updated: 2020/02/04 15:06:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char	*load_song(const Uint8 *key)
{
	if (key[SDL_SCANCODE_1])
		return ("./audio/Crustacean Shindig.ogg");
	if (key[SDL_SCANCODE_2])
		return ("./audio/DiGiorno.ogg");
	if (key[SDL_SCANCODE_3])
		return ("./audio/Hydra.ogg");
	if (key[SDL_SCANCODE_4])
		return ("./audio/The Classic.ogg");
	if (key[SDL_SCANCODE_5])
		return ("./audio/Bad Time.ogg");
	return (NULL);
}

void	play_music(t_map *map)
{
	Mix_Music	*music;
	char		*song;

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	song = NULL;
	if (map->state[SDL_SCANCODE_1] || map->state[SDL_SCANCODE_2] ||
		map->state[SDL_SCANCODE_3] || map->state[SDL_SCANCODE_4] ||
		map->state[SDL_SCANCODE_5])
		song = load_song(map->state);
	Mix_VolumeMusic(100);
	music = Mix_LoadMUS(song);
	Mix_PlayMusic(music, -1);
	if (map->state[SDL_SCANCODE_P])
		Mix_PauseMusic();
	if (map->state[SDL_SCANCODE_O])
		Mix_ResumeMusic();
}
