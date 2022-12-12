SRCS = mandatory/so_long.c \
	mandatory/get_map.c \
	mandatory/get_map_utils.c \
	mandatory/init.c \
	mandatory/move_player.c \
	mandatory/hooks.c \
	mandatory/exit_game.c \
	mandatory/load_player.c \

BONUS = bonus/so_long.c \
	bonus/get_map.c \
	bonus/get_map_utils.c \
	bonus/init.c \
	bonus/move_player.c \
	bonus/hooks.c \
	bonus/exit_game.c \
	bonus/load_player.c \
	bonus/monitoring.c \

NAME	= so_long

CFLAGS   = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM       = rm -f

CC 		= gcc

$(NAME):
	make -C libft
	make clean -C libft
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)

bonus:
	make -C libft
	make clean -C libft
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)_bonus

all: $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re $(NAME) bonus

# to be deleted
push:
	git add .
	git commit -m "updates"
	git push

level1:
	./so_long maps/map1.ber
level2:
	./so_long maps/map2.ber
level3:
	./so_long maps/map3.ber

brun:
	$(CC) $(CFLAGS) $(BONUS) $(MLXFLAGS) libft/libft.a -o $(NAME)_bonus
	./so_long_bonus maps/map1.ber

run:
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)
	./so_long maps/map1.ber