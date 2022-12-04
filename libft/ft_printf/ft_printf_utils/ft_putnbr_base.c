/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:17:41 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/18 12:17:14 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_base(long long unsigned n, char *base)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (n >= baselen)
		ft_putnbr_base(n / baselen, base);
	ft_putchar(base[n % baselen]);
	return (ft_basenblen(n, base));
}
