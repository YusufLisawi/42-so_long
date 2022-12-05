/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:26:26 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/05 19:32:26 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_d(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x + 1] != '1')
	{
		game->map.matrix[game->pos.y][game->pos.x] = '0';
		put_element('0', game->pos.x, game->pos.y, game);
		game->map.matrix[game->pos.y][game->pos.x + 1] = 'P';
		put_element('P', game->pos.x + 1, game->pos.y, game);
	}
}

void	key_s(t_game *game)
{
	if (game->map.matrix[game->pos.y + 1][game->pos.x] != '1')
	{
		game->map.matrix[game->pos.y][game->pos.x] = '0';
		put_element('0', game->pos.x, game->pos.y, game);
		game->map.matrix[game->pos.y + 1][game->pos.x] = 'P';
		put_element('P', game->pos.x, game->pos.y + 1, game);
	}
}

void	key_a(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x - 1] != '1')
	{
		game->map.matrix[game->pos.y][game->pos.x] = '0';
		put_element('0', game->pos.x, game->pos.y, game);
		game->map.matrix[game->pos.y][game->pos.x - 1] = 'P';
		put_element('P', game->pos.x - 1, game->pos.y, game);
	}
}

void	key_w(t_game *game)
{
	if (game->map.matrix[game->pos.y - 1][game->pos.x] != '1')
	{
		game->map.matrix[game->pos.y][game->pos.x] = '0';
		put_element('0', game->pos.x, game->pos.y, game);
		game->map.matrix[game->pos.y - 1][game->pos.x] = 'P';
		put_element('P', game->pos.x, game->pos.y - 1, game);
	}
}
