# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 11:36:55 by gmachado          #+#    #+#              #
#    Updated: 2020/01/30 17:49:12 by gmachado         ###   ########.fr        #
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
	-L ./includes/minilibx_macos_sierra -l mlx \

SRCS = \
	./srcs/wolf3d.c \
	./srcs/initializing.c \
	./srcs/map.c \
	./srcs/keys.c \
	./srcs/math.c \
	./srcs/textures.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ echo Compiling...
	@ make -C ./includes/libft
	@ gcc -ggdb3 -O0 --std=c99 -Wall `sdl2-config --libs --cflags` -o $(NAME) $(SRCS) $(ARCHIVE) $(FRAMEWORKS) -g3 -fsanitize=address
	@ make -C ./includes/minilibx_macos_sierra
	@ echo Finished compiling! Run with ./wolf3d
	# gcc  -o $(NAME) $(SRCS) $(ARCHIVE) -g3 -fsanitize=address -framework OpenGL -framework Appkit

clean:
	@ make -C ./includes/libft clean
	@ make -C ./includes/minilibx_macos_sierra clean
	@ rm -f $(OFILES)

fclean:
	@ make -C ./includes/libft fclean
	@ rm -f $(NAME)

re: fclean all
