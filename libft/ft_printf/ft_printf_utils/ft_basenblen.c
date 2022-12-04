/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basenblen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:05:49 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/18 19:13:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_basenblen(unsigned long long nb, char *base)
{
	int		i;
	size_t	baselen;

	baselen = ft_strlen(base);
	i = 1;
	while (nb >= baselen)
	{
		nb = nb / baselen;
		i++;
	}
	return (i);
}
