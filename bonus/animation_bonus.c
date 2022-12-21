/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:27:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/21 18:09:14 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delay(t_game *game)
{
	while (game->frame % 5000 != 0)
		game->frame++;
}

void	render_col(t_game *game, t_list *col)
{
	static int		i;

	if (i == 7)
		i = 0;
	if (game->frame % 900 == 0 && game->map.matrix[col->y][col->x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->bg.img, col->x * TILE_SIZE, col->y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win,
			game->coll[i].img, col->x * TILE_SIZE, col->y * TILE_SIZE);
		i++;
	}
}

int	animate_colls(t_game *game)
{
	t_list			*col;

	col = game->c_cords;
	while (col != NULL)
	{
		render_col(game, col);
		col = col->next;
	}
	game->frame++;
	return (0);
}
