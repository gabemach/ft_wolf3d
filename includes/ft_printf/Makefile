# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:46:58 by gmachado          #+#    #+#              #
#    Updated: 2019/12/17 13:47:20 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = $(wildcard *.c)

OFILES = *.o

CFLAGS = -Wall -Wextra -Werror -c -g

INCLUDES = -L ../libft

HEADER = -I ft_printf.h

all: $(NAME)

$(NAME): $(CFILES)
	@ make -C ../libft
	@ gcc $(CFLAGS) $(CFILES)
	@ ar rc $(NAME) $(OFILES) ../libft/*.o
	@ ranlib $(NAME)

clean:
	@ make -C ../libft clean
	@ rm -f $(OFILES)

fclean: clean
	@ make -C ../libft fclean
	@ rm -f $(NAME)

re: fclean all
