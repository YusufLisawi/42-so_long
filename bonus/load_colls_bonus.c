/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:35:59 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/21 12:54:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_colls_images(t_game *game)
{
	game->coll[0].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/1.xpm", &(game->coll[0].img_width),
			&(game->coll[0].img_height));
	game->coll[1].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/2.xpm", &(game->coll[1].img_width),
			&(game->coll[1].img_height));
	game->coll[2].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/3.xpm", &(game->coll[2].img_width),
			&(game->coll[2].img_height));
	game->coll[3].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/4.xpm", &(game->coll[3].img_width),
			&(game->coll[3].img_height));
	game->coll[4].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/5.xpm", &(game->coll[4].img_width),
			&(game->coll[4].img_height));
	game->coll[5].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/6.xpm", &(game->coll[5].img_width),
			&(game->coll[5].img_height));
	game->coll[6].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/7.xpm", &(game->coll[6].img_width),
			&(game->coll[6].img_height));
	game->coll[7].img = mlx_xpm_file_to_image(
			game->mlx, "assets/coll/8.xpm", &(game->coll[7].img_width),
			&(game->coll[7].img_height));
}

void	load_colls(t_game *game)
{
	game->c_cords = NULL;
	load_colls_images(game);
	if (!(game->coll[0].img) || !(game->coll[1].img)
		|| !(game->coll[2].img) || !(game->coll[3].img)
		|| !(game->coll[4].img) || !(game->coll[5].img)
		|| !(game->coll[6].img) || !(game->coll[7].img))
		exit_with_error(game, "Failure in loading collectibles images");
}

void	put_coll(t_game *game, int x, int y)
{
	t_list	*cpos;

	cpos = ft_lstnew_pos(x, y);
	ft_lstadd_front(&game->c_cords, cpos);
	mlx_put_image_to_window(game->mlx, game->win,
		game->coll[0].img, x * TILE_SIZE, y * TILE_SIZE);
}
