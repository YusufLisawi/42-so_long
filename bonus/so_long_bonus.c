/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/23 11:22:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	gameover(t_game *game)
{
	ft_printf(COLOR_RED "\n----- You Lose -----\n"COLOR_RESET \
	"You have been Bitten by skull zombie !!\n" \
	"%d moves, is that your best?\n", game->mvt);
	exit_game(game, 0);
}

void	elems_init(t_elem *elm)
{
	elm->count_c = 0;
	elm->count_e = 0;
	elm->count_p = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (throw_err(ERR_ARG));
	elems_init(&game.elem);
	game.mvt = 0;
	game.map.matrix = get_map(argv[1], \
			&game.map.width, \
			&game.map.height, &game.elem);
	if (!game.map.matrix)
		return (throw_err("Failed loading map"));
	game_init(&game);
	parse_map(&game);
	game.frame = 0;
	mlx_loop_hook(game.mlx, animate, &game);
	mlx_hook(game.win, 2, 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, press_red_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
