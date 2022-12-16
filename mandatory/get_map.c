/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:46:34 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/16 16:27:03 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
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
			throw_err(strerror(errno));
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

int	is_rect(char *line, int width)
{
	if (get_width(line) != width)
	{
		throw_err(ERR_RECT);
		return (0);
	}
	return (1);
}

char	*read_map(int fd, int *width, int *height)
{
	char	*line;
	char	*map;

	line = get_next_line(fd);
	if (!line)
	{
		throw_err("Invalid map file.");
		return (0);
	}
	map = ft_strdup(line);
	(*width) = get_width(line);
	(*height) = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!is_rect(line, *width) || !is_valid_elements(line))
			return (0);
		map = ft_strjoin(map, line);
		free(line);
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
	if (!is_wall(map, *height) || !is_elements_count(map, elements, *height,
			*width) || !is_valid_path(map_str, *elements))
	{
		free_map(map);
		map = NULL;
	}
	free(map_str);
	close(fd);
	return (map);
}
