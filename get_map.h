/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:47:28 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 14:45:24 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <fcntl.h>

typedef struct s_elements
{
	int	count_e;
	int	count_c;
	int	count_p;
}	t_elem;

int		check_filename_ext(char *filename, char *ext);
int		is_valid_elements(char *line);
int		get_width(char *line);
int		is_wall(char **map, int height);
int		is_elements_count(char **map, t_elem *elements, int height, int width);
char	**get_map(char *filename, int *width, int *height, t_elem *elements);
void	elems_init(t_elem *elm);

#endif