/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:34 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/16 16:48:45 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	press_red_cross(t_game *game)
{
	if (game->elem.count_c > 0)
	{
		ft_printf(COLOR_RED "\n----- You Lose -----\n"COLOR_RESET \
			"is that your best?\n", game->mvt);
	}
	exit_game(game, 0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode != KEY_ESC && game->elem.count_e != 0)
		move_player(keycode, game);
	else if (keycode == KEY_ESC)
	{
		if (game->elem.count_c > 0)
		{
			ft_printf(COLOR_RED "\n----- You Lose -----\n"COLOR_RESET \
				"is that your best?\n", game->mvt);
		}
		exit_game(game, 0);
	}
	return (0);
}
