# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 18:39:24 by ltuffery          #+#    #+#              #
#    Updated: 2023/01/16 22:46:12 by ltuffery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -Ofast -g

NAME	=	fdf

SRCS	=	srcs/parse_file.c \
			srcs/error.c \
			srcs/clean.c \
			srcs/utils.c \
			srcs/events.c \
			srcs/main.c

OBJS	=	$(SRCS:.c=.o)

%.o:			%.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $^ -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -s -C libft
	$(CC) $(OBJS) libft/libft.a -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@make fclean -s -C libft

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	re all clean fclean
