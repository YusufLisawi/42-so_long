/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:44:39 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 15:54:14 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_map.h"

int main()
{
	char **map;
	int map_width;
	int map_height;
	t_elem	elem;

	elems_init(&elem);
	map = get_map("map.ber", &map_width, &map_height, &elem);
	if (map)
	{
		ft_printf("count c -> %d\n", elem.count_c);
		ft_printf("count p -> %d\n", elem.count_p);
		ft_printf("count e -> %d\n", elem.count_e);
		ft_printf("height : %i - width : %i\n", map_height, map_width);
	}
	free(map);

}