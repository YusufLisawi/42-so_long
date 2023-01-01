/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:42:18 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/21 12:55:42 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	destroy_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(game->mlx, game->coll[i].img);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->enemy[i].img);
		i++;
	}
}

void	exit_game(t_game *game, int code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->bg.img);
	mlx_destroy_image(game->mlx, game->exit_false.img);
	mlx_destroy_image(game->mlx, game->exit_true.img);
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			mlx_destroy_image(game->mlx, game->player[i][j].img);
			j++;
		}
		i++;
	}
	destroy_img(game);
	free_map(game->map.matrix);
	exit(code);
}

void	exit_with_error(t_game *game, char *msg)
{
	free_map(game->map.matrix);
	throw_err(msg);
	exit(0);
}

int	throw_err(char *type)
{
	ft_printf(COLOR_RED "Error\n" COLOR_RESET "%s\n", type);
	return (0);
}
