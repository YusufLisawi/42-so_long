/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:27 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 16:08:58 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**map;
	int		map_width;
	int		map_height;
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
