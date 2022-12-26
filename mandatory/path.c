/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:10:15 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/16 16:26:32 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos(char **map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (map[*y])
	{
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
		*x = 0;
	}
}

int	check_path(char **map, int x, int y, t_elem *el)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			el->count_c--;
		if (map[y][x] == 'E')
			el->count_e--;
		map[y][x] = '1';
		if (map[y][x + 1] != '1')
			check_path(map, x + 1, y, el);
		if (map[y][x - 1] != '1')
			check_path(map, x - 1, y, el);
		if (map[y - 1][x] != '1')
			check_path(map, x, y - 1, el);
		if (map[y + 1][x] != '1')
			check_path(map, x, y + 1, el);
		if (el->count_e == 0 && el->count_c == 0)
			return (1);
	}
	return (0);
}

int	is_valid_path(char *map, t_elem el)
{
	int		x;
	int		y;
	char	**matrix;

	matrix = ft_split(map, '\n');
	get_pos(matrix, &x, &y);
	if (!check_path(matrix, x, y, &el))
	{
		free_map(matrix);
		return (throw_err("There's no path for this map"));
	}
	free_map(matrix);
	matrix = NULL;
	free(map);
	return (1);
}
