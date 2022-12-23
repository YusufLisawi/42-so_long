/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:58:09 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/23 11:29:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_dir(t_game *game, t_list *enm, int x, int y)
{
	put_element('0', enm->x, enm->y, game);
	game->map.matrix[enm->y][enm->x] = '0';
	enm->x += x;
	enm->y += y;
}

int	can_move(t_game *game, char c)
{
	if (c == 'P')
		game->elem.count_p -= 1;
	if (c == '0' || c == 'P')
		return (1);
	return (0);
}

void	choose_dir(t_game *game, t_list *enm, int dir)
{
	if (dir == 0)
	{
		if (can_move(game, game->map.matrix \
			[enm->y][enm->x + 1]))
			set_dir(game, enm, 1, 0);
	}
	if (dir == 1)
	{
		if (can_move(game, game->map.matrix \
			[enm->y][enm->x - 1]))
			set_dir(game, enm, -1, 0);
	}
	if (dir == 2)
	{
		if (can_move(game, game->map.matrix \
			[enm->y + 1][enm->x]))
			set_dir(game, enm, 0, 1);
	}
	if (dir == 3)
	{
		if (can_move(game, game->map.matrix \
			[enm->y - 1][enm->x]))
			set_dir(game, enm, 0, -1);
	}
}

void	move_enemy(t_game *game)
{
	int		dir;
	t_list	*enm;

	enm = game->e_cords;
	while (enm)
	{
		dir = rand() % 4;
		choose_dir(game, enm, dir);
		game->map.matrix[enm->y][enm->x] = 'X';
		enm = enm->next;
	}
	if (game->elem.count_p == 0)
		gameover(game);
}
