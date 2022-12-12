/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:57:19 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/12 10:07:33 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_up(t_game *game)
{
	game->player[0][0].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/up0.xpm", \
			&(game->player[0][0].img_width), &(game->player[0][0].img_height));
	game->player[0][1].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/up1.xpm", \
			&(game->player[0][1].img_width), &(game->player[0][1].img_height));
	game->player[0][2].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/up2.xpm", \
			&(game->player[0][2].img_width), &(game->player[0][2].img_height));
	if (!(game->player[0][0].img) || !(game->player[0][1].img) \
		|| !(game->player[0][2].img))
		exit_with_error(game, "Failure in loading player images");
}

void	load_player_left(t_game *game)
{
	game->player[1][0].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/left0.xpm", \
			&(game->player[1][0].img_width), &(game->player[1][0].img_height));
	game->player[1][1].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/left1.xpm", \
			&(game->player[1][1].img_width), &(game->player[1][1].img_height));
	game->player[1][2].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/left2.xpm", \
			&(game->player[1][2].img_width), &(game->player[1][2].img_height));
	if (!(game->player[1][0].img) || !(game->player[1][1].img) \
		|| !(game->player[1][2].img))
		exit_with_error(game, "Failure in loading player images");
}

void	load_player_down(t_game *game)
{
	game->player[2][0].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/down0.xpm", \
			&(game->player[2][0].img_width), &(game->player[2][0].img_height));
	game->player[2][1].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/down1.xpm", \
			&(game->player[2][1].img_width), &(game->player[2][1].img_height));
	game->player[2][2].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/down2.xpm", \
			&(game->player[2][2].img_width), &(game->player[2][2].img_height));
	if (!(game->player[2][0].img) || !(game->player[2][1].img) \
		|| !(game->player[2][2].img))
		exit_with_error(game, "Failure in loading player images");
}

void	load_player_right(t_game *game)
{
	game->player[3][0].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/right0.xpm", \
			&(game->player[3][0].img_width), &(game->player[3][0].img_height));
	game->player[3][1].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/right1.xpm", \
			&(game->player[3][1].img_width), &(game->player[3][1].img_height));
	game->player[3][2].img = mlx_xpm_file_to_image(\
			game->mlx, "assets/player/right2.xpm", \
			&(game->player[3][2].img_width), &(game->player[3][2].img_height));
	if (!(game->player[3][0].img) || !(game->player[3][1].img) \
		|| !(game->player[3][2].img))
		exit_with_error(game, "Failure in loading player images");
}

void	load_player(t_game *game)
{
	load_player_up(game);
	load_player_left(game);
	load_player_down(game);
	load_player_right(game);
}
