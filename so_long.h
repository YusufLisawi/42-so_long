/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/05 16:59:26 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// Libs
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include "get_map.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
// Colors
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_RESET   "\x1b[0m"
// Errors
# define ERR_BER	"Invalid map file (.ber)"
# define ERR_ELMS	"The map must contain 1 (E), at least 1 (C), and 1 (P)."
# define ERR_RECT	"The map must be rectangular."
# define ERR_WALL	"The map must be closed/surrounded by walls."
// Game
# define TILE_SIZE 40

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	t_img		wall;
	t_img		coll;
	t_img		player;
	t_img		bg;
	t_img		exit_false;
	t_img		exit_true;

	t_map		map;
}	t_game;

int		throw_err(char *type);
void	game_init(t_game *game);
void	parse_map(t_game *game);

#endif