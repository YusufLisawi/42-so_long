/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:26:26 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/06 11:33:03 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x] == 'C')
	{
		game->elem.count_c = game->elem.count_c - 1;
		game->map.matrix[game->pos.y][game->pos.x] = '0';
	}
	if (game->elem.count_c == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_true.img,
			game->pos.x_e * TILE_SIZE, game->pos.y_e * TILE_SIZE);
		game->map.matrix[game->pos.y_e][game->pos.x_e] = 'e';
	}
}

void	move(t_game *game, int x, int y)
{
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] == '1'
		|| (game->map.matrix[game->pos.y + y][game->pos.x + x] == 'E'))
		return ;
	put_element('0', game->pos.x, game->pos.y, game);
	put_element('P', game->pos.x + x, game->pos.y + y, game);
	collect(game);
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] == 'e')
	{
		ft_printf("You win");
		exit(0);
	}
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == 126)
		move(game, 0, -1);
	else if (keycode == KEY_A || keycode == 123)
		move(game, -1, 0);
	else if (keycode == KEY_S || keycode == 125)
		move(game, 0, 1);
	else if (keycode == KEY_D || keycode == 124)
		move(game, 1, 0);
}
