/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:26:26 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/05 20:30:47 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, int x, int y)
{
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] != '1')
	{
		game->map.matrix[game->pos.y][game->pos.x] = '0';
		put_element('0', game->pos.x, game->pos.y, game);
		game->map.matrix[game->pos.y + y][game->pos.x + x] = 'P';
		put_element('P', game->pos.x + x, game->pos.y + y, game);
		if (game->map.matrix[game->pos.y + y][game->pos.x + x] == 'C')
		{
			game->elem.count_c = game->elem.count_c - 1;
			// game->map.matrix[game->pos.y + y][game->pos.x + x] = 'P';
		}
	}
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_D)
		move(game, 1, 0);
	else if (keycode == KEY_W)
		move(game, 0, -1);
	else if (keycode == KEY_S)
		move(game, 0, 1);
	else if (keycode == KEY_A)
		move(game, -1, 0);
}
