/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:27:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/22 20:03:01 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_col(t_game *game, t_list *col)
{
	if (game->map.matrix[col->y][col->x] == 'C')
	{
		put_element('0', col->x, col->y, game);
		mlx_put_image_to_window(game->mlx, game->win,
			game->coll[game->frame % 7].img, \
			col->x * TILE_SIZE, col->y * TILE_SIZE);
	}
}

void	render_enemy(t_game *game, t_list *enm)
{
	put_element('0', enm->x, enm->y, game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy[game->frame % 3].img, \
		enm->x * TILE_SIZE, enm->y * TILE_SIZE);
}

void	render(t_game *game, t_list *enm, t_list *col)
{
	if (game->frame % 1200 == 0)
	{
		while (col != NULL)
		{
			render_col(game, col);
			col = col->next;
		}
	}
	if (game->frame % 1400 == 0)
	{
		while (enm != NULL)
		{
			render_enemy(game, enm);
			enm = enm->next;
		}
	}
}

int	animate(t_game *game)
{
	t_list			*col;
	t_list			*enm;

	col = game->c_cords;
	enm = game->e_cords;
	render(game, enm, col);
	if (game->frame % 3000 == 0)
	{
		move_enemy(game);
	}
	game->frame++;
	return (0);
}
