/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:14:10 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 19:37:19 by yelaissa         ###   ########.fr       */
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
			"./assets/player.xpm", &game->player.img_width,
			&game->player.img_height);
	game->exit_false.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit_false.xpm", &game->exit_false.img_width,
			&game->exit_false.img_height);
	game->exit_true.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit_true.xpm", &game->exit_true.img_width,
			&game->exit_true.img_height);
}

void	game_init(char **map_matrix, int width, int height, t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width * TILE_SIZE,
			height * TILE_SIZE, "so_long");
	memcpy(game->map, map_matrix, sizeof(char *) * height);
	images_init(game);
}

void	put_assets(t_game *game)
{
	return (0);
}
// int	main_loop(t_game *game)
// {
// 	draw_rectangles(game);
// 	draw_lines(game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
// 	return (0);
// }
