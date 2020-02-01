# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 15:50:16 by gmachado          #+#    #+#              #
#    Updated: 2019/12/17 13:47:38 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES = *.c \

OFILES = *.o

all: $(NAME)

$(NAME):
	@ gcc -c -Wall -Wextra -Werror -I libft.h $(CFILES)
	@ ar rc $(NAME) $(OFILES)
	@ ranlib $(NAME)

clean:
	@ rm -f $(OFILES)

fclean:
	@ rm -f $(OFILES) $(NAME)

re: fclean all

.PHONY: clean fclean all re
