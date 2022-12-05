/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/05 17:33:37 by yelaissa         ###   ########.fr       */
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

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_D)
	{
		if (game->map.matrix[game->pos.y][game->pos.x + 1] != '1')
		{
			game->map.matrix[game->pos.y][game->pos.x] = '0';
			put_element('0', game->pos.x, game->pos.y, game);
			game->map.matrix[game->pos.y][game->pos.x + 1] = 'P';
			put_element('P', game->pos.x + 1, game->pos.y, game);
		}
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	t_elem	elem;

	elems_init(&elem);
	game.map.matrix = get_map("map.ber", \
			&game.map.width, \
			&game.map.height, \
			&elem);
	if (!game.map.matrix)
		return (0);
	game_init(&game);
	parse_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	free_map(game.map.matrix);
}
