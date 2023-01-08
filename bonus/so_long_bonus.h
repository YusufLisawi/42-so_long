/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:52:48 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/23 15:03:58 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
// Libs
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_map_bonus.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
// Colors
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_RESET "\x1b[0m"
// Errors
# define ERR_BER "Invalid map file (.ber)"
# define ERR_ELMS "The map must contain 1 (E), at least 1 (C), and 1 (P)."
# define ERR_RECT "The map must be rectangular."
# define ERR_WALL "The map must be closed/surrounded by walls."
# define ERR_ARG "Please enter 1 map file as argument."
// Game
# define TILE_SIZE 40

// Keys
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
}			t_map;

typedef struct s_pos
{
	int		x;
	int		y;

	int		x_e;
	int		y_e;
}			t_pos;

typedef struct s_game
{
	void					*mlx;
	void					*win;
	int						mvt;
	t_img					wall;
	t_img					coll[8];
	t_img					player[4][3];
	t_img					bg;
	t_img					exit_false;
	t_img					exit_true;

	t_map					map;
	t_elem					elem;
	t_pos					pos;

	t_img					enemy[4];
	t_list					*e_cords;
	t_list					*c_cords;

	long unsigned int		frame;
}			t_game;

void		elems_init(t_elem *elm);
int			throw_err(char *type);
void		game_init(t_game *game);
void		parse_map(t_game *game);
void		put_element(char c, int x, int y, t_game *game);
void		move_player(int keycode, t_game *game);
void		free_map(char **map);
int			press_red_cross(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		exit_game(t_game *game, int code);
void		exit_with_error(t_game *game, char *msg);
void		load_player(t_game *game);
void		put_bg(t_game *game);
void		free_map(char **map);
void		monitor_moves(t_game *game);
int			is_valid_path(char *map, t_elem el);
void		gameover(t_game *game);

void		load_enemy(t_game *game);
void		put_enemy(t_game *game, int x, int y);
void		move_enemy(t_game *game);

void		load_colls(t_game *game);
void		put_coll(t_game *game, int x, int y);
int			animate(t_game *game);
#endif