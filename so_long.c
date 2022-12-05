/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/05 16:59:58 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{
	t_game	game;
	t_elem	elem;

	elems_init(&elem);
	game.map.matrix = get_map("map.ber",
			&game.map.width,
			&game.map.height,
			&elem);
	if (!game.map.matrix)
		return (0);
	game_init(&game);
	parse_map(&game);
	mlx_loop(game.mlx);
	free_map(game.map.matrix);
}
