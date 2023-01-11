SRCS = mandatory/so_long.c \
	mandatory/get_map.c \
	mandatory/get_map_utils.c \
	mandatory/init.c \
	mandatory/move_player.c \
	mandatory/hooks.c \
	mandatory/exit_game.c \
	mandatory/load_player.c \
	mandatory/path.c

OBJS = $(SRCS:c=o)

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

OBJS_B = $(BONUS:c=o)

NAME	= so_long

NAME_B	= so_long_bonus

CFLAGS   = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM       = rm -f

CC 		= gcc

LIBFT		= libft/libft.a

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B): $(LIBFT) $(OBJS_B)
		$(CC) $(CFLAGS) $(OBJS_B) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(LIBFT):	
		make all -C libft
		make bonus -C libft

all:	$(NAME)

bonus: $(NAME_B)

clean:	
		$(RM) $(OBJS_B) $(OBJS) 
		make fclean -C libft
	
fclean:	clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)

re:	fclean all


.PHONY:	all clean fclean re bonus