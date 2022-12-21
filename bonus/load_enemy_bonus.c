/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:06:01 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/21 12:35:31 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_game *game)
{
	game->e_cords = NULL;
	game->enemy[0].img = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy/e0.xpm", &(game->enemy[0].img_width),
			&(game->enemy[0].img_height));
	game->enemy[1].img = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy/e1.xpm", &(game->enemy[1].img_width),
			&(game->enemy[1].img_height));
	game->enemy[2].img = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy/e2.xpm", &(game->enemy[2].img_width),
			&(game->enemy[2].img_height));
	game->enemy[3].img = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy/e3.xpm", &(game->enemy[3].img_width),
			&(game->enemy[3].img_height));
	if (!(game->enemy[0].img) || !(game->enemy[1].img)
		|| !(game->enemy[2].img) || !(game->enemy[3].img))
		exit_with_error(game, "Failure in loading enemy images");
}

void	put_enemy(t_game *game, int x, int y)
{
	t_list	*epos;

	epos = ft_lstnew_pos(x, y);
	ft_lstadd_front(&game->e_cords, epos);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy[0].img, x * TILE_SIZE, y * TILE_SIZE);
}
