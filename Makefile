# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 18:39:24 by ltuffery          #+#    #+#              #
#    Updated: 2023/01/10 16:50:00 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g

NAME	=	fdf

SRCS	=	srcs/window.c

OBJS	=	$(SRCS:.c=.o)

%o:			%.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	re all clean fclean
