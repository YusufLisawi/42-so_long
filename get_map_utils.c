/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:47:18 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/05 16:59:09 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

int	is_valid_elements(char *line)
{
	int	i;

	i = 0;
	while (i < get_width(line))
	{
		if (ft_strrchr("01CPE", line[i]) == NULL)
			return (throw_err(ERR_ELMS));
		i++;
	}
	return (1);
}

int	is_wall(char **map, int height)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' || map[height - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (throw_err(ERR_WALL));
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][get_width(map[i]) - 1] != '1')
			return (throw_err(ERR_WALL));
		i++;
	}
	return (1);
}

int	is_elements_count(char **map, t_elem *elements, int height, int width)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < height - 1)
	{
		j = 0;
		while (j < width - 1)
		{
			if (map[i][j] == 'C')
				(elements->count_c)++;
			else if (map[i][j] == 'P')
				(elements->count_p)++;
			else if (map[i][j] == 'E')
				(elements->count_e)++;
			j++;
		}
		i++;
	}
	if (elements->count_c < 1 || elements->count_p != 1
		|| elements->count_e != 1)
		return (throw_err(ERR_ELMS));
	return (1);
}
