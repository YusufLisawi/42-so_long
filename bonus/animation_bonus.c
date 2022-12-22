/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:27:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/22 13:32:35 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_col(t_game *game, t_list *col)
{
	static int		i;

	if (i == 7)
		i = 0;
	if (game->frame % 900 == 0)
	{
		if (game->map.matrix[col->y][col->x] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->bg.img, col->x * TILE_SIZE, col->y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->win,
				game->coll[i].img, col->x * TILE_SIZE, col->y * TILE_SIZE);
		}
		i++;
	}
}

void	render_enemy(t_game *game, t_list *enm)
{
	static int		i;

	if (i == 3)
		i = 0;
	if (game->frame % 1200 == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->bg.img, enm->x * TILE_SIZE, enm->y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy[i].img, enm->x * TILE_SIZE, enm->y * TILE_SIZE);
		i++;
	}
}

int	animate(t_game *game)
{
	t_list			*col;
	t_list			*enm;

	col = game->c_cords;
	enm = game->e_cords;
	while (col != NULL)
	{
		render_col(game, col);
		col = col->next;
	}
	while (enm != NULL)
	{
		render_enemy(game, enm);
		enm = enm->next;
	}
	game->frame++;
	return (0);
}
