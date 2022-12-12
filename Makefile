SRCS = mandatory/so_long.c \
	mandatory/get_map.c \
	mandatory/get_map_utils.c \
	mandatory/init.c \
	mandatory/move_player.c \
	mandatory/hooks.c \
	mandatory/exit_game.c \
	mandatory/load_player.c \

NAME	= so_long

CFLAGS   = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM       = rm -f

CC 		= gcc

$(NAME):
	make -C libft
	make clean -C libft
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)

all: $(NAME)

run:
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)
	./so_long maps/map1.ber

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re $(NAME)

push:
	git add .
	git commit -m "updates"
	git push