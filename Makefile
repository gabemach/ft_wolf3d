# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 11:36:55 by gmachado          #+#    #+#              #
#    Updated: 2020/02/06 14:39:44 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

HEADER = \
	-I ./includes/wolf3d.h

FRAMEWORKS = \
	-I ./Frameworks/SDL2.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_image.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_ttf.framework/Versions/A/Headers \
	-I ./Frameworks/SDL2_mixer.framework/Versions/A/Headers \
	-F ./Frameworks/

ARCHIVE = \
	-L ./includes/libft -l ft \

SRCS = \
	./srcs/wolf3d.c \
	./srcs/initializing.c \
	./srcs/map.c \
	./srcs/keys.c \
	./srcs/math.c \
	./srcs/textures.c \
	./srcs/c_f_calcs.c \
	./srcs/audio.c \
	./srcs/reader.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc -c $< -o $@ -ggdb3 -O0 --std=c99 -Wall `sdl2-config --libs --cflags` -l SDL2_mixer

all: $(NAME)

$(NAME): $(OBJS)
	@ echo Compiling...
	@ make -C ./includes/libft
	@ gcc -ggdb3 -O0 --std=c99 -Wall `sdl2-config --libs --cflags` -l SDL2_mixer -o $(NAME) $(OBJS) $(ARCHIVE) $(FRAMEWORKS) -g
	@ echo Finished compiling! Run with ./wolf3d {map path}

clean:
	@ make -C ./includes/libft clean
	@ rm -f $(OBJS)

fclean: clean
	@ make -C ./includes/libft fclean
	@ rm -f $(NAME)

re: fclean all