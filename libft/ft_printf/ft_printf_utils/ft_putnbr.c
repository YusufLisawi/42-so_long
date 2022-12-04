/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:46:49 by yelaissa          #+#    #+#             */
/*   Updated: 2022/03/31 14:50:11 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#define BASE10 "0123456789"

int	ft_put_itoa(long n)
{
	int		size;

	size = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		size += 1;
	}
	size += ft_putnbr_base(n, BASE10);
	return (size);
}

int	ft_put_uitoa(unsigned int n)
{
	int	size;

	size = 0;
	size += ft_putnbr_base(n, BASE10);
	return (size);
}
