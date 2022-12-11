/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:34 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/11 12:08:50 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_red_cross(t_game *game)
{
	free_map(game->map.matrix);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode != KEY_ESC && game->elem.count_e != 0)
		move_player(keycode, game);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(game->map.matrix);
		exit(0);
	}
	return (0);
}
