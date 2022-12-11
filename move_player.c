/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:26:26 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/11 14:27:31 by yelaissa         ###   ########.fr       */
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

void	check_exit(t_game *game)
{
	if (game->map.matrix[game->pos.y][game->pos.x] == 'e')
	{
		mlx_string_put(game->mlx, game->win,
			game->pos.x_e * TILE_SIZE + TILE_SIZE,
			game->pos.y_e * TILE_SIZE + 8, 0xFFFFFF, "You win");
		game->elem.count_e = game->elem.count_e - 1;
		ft_printf(COLOR_GREEN "\n----- You win -----\n" COLOR_RESET);
	}
}

void	move(t_game *game, int x, int y)
{
	if (game->map.matrix[game->pos.y + y][game->pos.x + x] == '1')
		return ;
	if (game->map.matrix[game->pos.y][game->pos.x] != 'E')
		put_element('0', game->pos.x, game->pos.y, game);
	put_element('P', game->pos.x + x, game->pos.y + y, game);
	collect(game);
	check_exit(game);
	ft_printf("Mouvement : %d\n", ++game->mvt);
}

void	move_player(int keycode, t_game *game)
{
	if (game->elem.count_c != 0)
		put_element('E', game->pos.x_e, game->pos.y_e, game);
	if (keycode == KEY_W || keycode == 126)
		move(game, 0, -1);
	else if (keycode == KEY_A || keycode == 123)
		move(game, -1, 0);
	else if (keycode == KEY_S || keycode == 125)
		move(game, 0, 1);
	else if (keycode == KEY_D || keycode == 124)
		move(game, 1, 0);
	ft_printf("(%d, %d)\n", game->pos.x, game->pos.y);
	ft_printf("c : %d\n", game->elem.count_c);
	ft_printf("e : %d\n", game->elem.count_e);
}
