/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/06 11:22:44 by yelaissa         ###   ########.fr       */
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
	ft_printf("%d\n", game->elem.count_c);
	if (keycode != KEY_ESC)
		move_player(keycode, game);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(game->map.matrix);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	elems_init(&game.elem);
	game.map.matrix = get_map("map.ber", \
			&game.map.width, \
			&game.map.height, \
			&game.elem);
	if (!game.map.matrix)
		return (0);
	game_init(&game);
	parse_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	free_map(game.map.matrix);
	return (0);
}
