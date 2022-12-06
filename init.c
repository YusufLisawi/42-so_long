/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:14:10 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/06 11:25:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_init(t_game *game)
{
	game->bg.img = mlx_xpm_file_to_image(game->mlx, "./assets/bg.xpm",
			&game->bg.img_width, &game->bg.img_height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->wall.img_width, &game->wall.img_height);
	game->coll.img = mlx_xpm_file_to_image(game->mlx, "./assets/coll.xpm",
			&game->coll.img_width, &game->coll.img_height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/playerD.xpm", &game->player.img_width,
			&game->player.img_height);
	game->exit_false.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit_false.xpm", &game->exit_false.img_width,
			&game->exit_false.img_height);
	game->exit_true.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit_true.xpm", &game->exit_true.img_width,
			&game->exit_true.img_height);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE, game->map.height * TILE_SIZE,
			"so_long");
	images_init(game);
}

void	put_element(char c, int x, int y, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->bg.img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img,
			x * TILE_SIZE, y * TILE_SIZE);
		game->pos.x = x;
		game->pos.y = y;
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_false.img, x * TILE_SIZE, y * TILE_SIZE);
		game->pos.x_e = x;
		game->pos.y_e = y;
	}
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coll.img,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	parse_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while ((game->map.matrix)[row])
	{
		col = 0;
		while ((game->map.matrix)[row][col])
		{
			put_element((game->map.matrix)[row][col], col, row, game);
			col++;
		}
		row++;
	}
}

void	elems_init(t_elem *elm)
{
	elm->count_c = 0;
	elm->count_e = 0;
	elm->count_p = 0;
}
