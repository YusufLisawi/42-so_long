/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:27:58 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/22 19:20:25 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_put_hexa(unsigned int n, char format)
{
	char			*base;
	int				size;

	size = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	size += ft_putnbr_base(n, base);
	return (size);
}

int	ft_put_pointer(long unsigned n)
{
	char	*base;
	int		size;

	size = 0;
	base = "0123456789abcdef";
	size += ft_putstr("0x");
	if (n == 0)
		size += ft_putchar('0');
	else
		size += ft_putnbr_base(n, base);
	return (size);
}
