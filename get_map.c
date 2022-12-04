/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:46:34 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 16:07:30 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *filename, int *fd)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	if (ft_strncmp("ber", dot + 1, 3) == 0)
	{
		*fd = open(filename, O_RDONLY);
		if (*fd == -1)
		{
			ft_printf(COLOR_RED "Error:\n" COLOR_RESET "%s\n", strerror(errno));
			close(*fd);
			return (0);
		}
	}
	else
	{
		throw_err(ERR_BER);
		return (0);
	}
	return (1);
}

void	elems_init(t_elem *elm)
{
	elm->count_c = 0;
	elm->count_e = 0;
	elm->count_p = 0;
}

char	*read_map(int fd, int *width, int *height)
{
	char	*line;
	char	*map;

	line = get_next_line(fd);
	map = ft_strdup(line);
	(*width) = get_width(line);
	(*height) = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (get_width(line) != *width)
		{
			throw_err(ERR_RECT);
			return (0);
		}
		else if (!is_valid_elements(line))
			return (0);
		map = ft_strjoin(map, line);
		(*height)++;
	}
	return (map);
}

char	**get_map(char *filename, int *width, int *height, t_elem *elements)
{
	int		fd;
	char	*map_str;
	char	**map;

	map = NULL;
	if (!check_file(filename, &fd))
		return (0);
	map_str = read_map(fd, width, height);
	if (!map_str)
		return (0);
	map = ft_split(map_str, '\n');
	if (!is_wall(map, *height)
		|| !is_elements_count(map, elements, *height, *width))
		map = NULL;
	close(fd);
	return (map);
}
