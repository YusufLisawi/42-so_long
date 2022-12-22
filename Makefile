SRCS = mandatory/so_long.c \
	mandatory/get_map.c \
	mandatory/get_map_utils.c \
	mandatory/init.c \
	mandatory/move_player.c \
	mandatory/hooks.c \
	mandatory/exit_game.c \
	mandatory/load_player.c \
	mandatory/path.c

BONUS = bonus/exit_game_bonus.c \
	bonus/get_map_bonus.c \
	bonus/get_map_utils_bonus.c \
	bonus/hooks_bonus.c \
	bonus/init_bonus.c \
	bonus/load_player_bonus.c \
	bonus/monitoring_bonus.c \
	bonus/move_player_bonus.c \
	bonus/path_bonus.c \
	bonus/so_long_bonus.c \
	bonus/load_enemy_bonus.c \
	bonus/load_colls_bonus.c \
	bonus/animation_bonus.c \
	bonus/move_enemy_bonus.c \

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
	make bonus -C libft
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

brun:
	$(CC) $(CFLAGS) $(BONUS) $(MLXFLAGS) libft/libft.a -o $(NAME)_bonus
	./so_long_bonus maps/map4.ber

run:
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) libft/libft.a -o $(NAME)
	./so_long maps/map1.ber