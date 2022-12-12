/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:47:18 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/12 14:43:17 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	monitor_moves(t_game *game)
{
	char	*moves;
	size_t	i;

	i = 0;
	moves = ft_itoa(game->mvt);
	while (i < ft_strlen(moves))
	{
		put_element('0', 3 + i, game->map.height, game);
		i++;
	}
	mlx_string_put(game->mlx, game->win, TILE_SIZE * 3, \
		TILE_SIZE * game->map.height + 5, 0xFFFFFF, moves);
}
