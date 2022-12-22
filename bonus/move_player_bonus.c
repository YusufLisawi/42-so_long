/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:26:26 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/22 19:23:50 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x] == 'C')
	{
		game->elem.count_c = game->elem.count_c - 1;
		game->map.matrix[game->pos.y][game->pos.x] = '0';
	}
	if (game->elem.count_c == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->exit_true.img, \
			game->pos.x_e * TILE_SIZE, game->pos.y_e * TILE_SIZE);
		game->map.matrix[game->pos.y_e][game->pos.x_e] = 'e';
	}
}

void	check_exit(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x] == 'e')
	{
		game->elem.count_e = game->elem.count_e - 1;
		ft_printf(COLOR_GREEN "\n----- You win -----\n"COLOR_RESET
			"with %d moves, \nis that your best?\n", game->mvt);
		exit_game(game, 0);
	}
}

void	set_player(t_game *game, int dir, int x, int y)
{
	game->pos.x = game->pos.x + x;
	game->pos.y = game->pos.y + y;
	game->map.matrix[game->pos.y - y][game->pos.x - x] = '0';
	game->map.matrix[game->pos.y][game->pos.x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, \
		game->player[dir][game->mvt % 3].img, \
		TILE_SIZE * game->pos.x, TILE_SIZE * game->pos.y);
}

void	move(t_game *game, int dir, int x, int y)
{
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] == '1')
		return ;
	if (game->elem.count_c != 0)
		put_element('E', game->pos.x_e, game->pos.y_e, game);
	if (game->map.matrix[game->pos.y][game->pos.x] != 'E')
		put_element('0', game->pos.x, game->pos.y, game);
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] == 'X')
	{
		game->elem.count_p = game->elem.count_p - 1;
		ft_printf(COLOR_RED "\n----- You Lose -----\n"COLOR_RESET \
		"You have been Bitten by skull monster !!\n" \
		"%d moves, is that your best?\n", game->mvt);
		exit_game(game, 0);
	}
	set_player(game, dir, x, y);
	collect(game);
	monitor_moves(game);
	game->mvt += 1;
	ft_printf("Moves : %d\n", game->mvt);
	check_exit(game);
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == 126)
		move(game, 0, 0, -1);
	else if (keycode == KEY_A || keycode == 123)
		move(game, 1, -1, 0);
	else if (keycode == KEY_S || keycode == 125)
		move(game, 2, 0, 1);
	else if (keycode == KEY_D || keycode == 124)
		move(game, 3, 1, 0);
}
