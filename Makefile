# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:15:48 by htalhaou          #+#    #+#              #
#    Updated: 2022/12/06 10:54:20 by yelaissa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = so_long.c \
	get_map.c \
	get_map_utils.c \
	error_log.c \
	init.c \
	move_player.c \

NAME    = so_long

CFLAGS   = -Wall -Wextra -Werror

RM        = rm -f

CC 		= gcc

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a
	./a.out

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re