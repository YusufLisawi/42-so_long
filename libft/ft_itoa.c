/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:12:06 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/15 19:22:38 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	ft_nblen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 1;
	if (n < 0)
		sign *= -1;
	len = ft_nblen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = 48 + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
