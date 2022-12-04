/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:16:18 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/04 08:55:06 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	memory = malloc(count * size);
	if (!memory)
		return (0);
	ft_bzero(memory, count * size);
	return (memory);
}
